#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;     // Left subarray
    int j = mid + 1;  // Right subarray
    int k = left;     // Merged array
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);  // Count inversions
        }
    }

    // Copy remaining elements of left subarray
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements of right subarray
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy merged elements back to original array
    for (int x = left; x <= right; x++)
        arr[x] = temp[x];

    return inv_count;
}

long long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);       // Left half
        inv_count += mergeSort(arr, temp, mid + 1, right);  // Right half

        inv_count += merge(arr, temp, left, mid, right);    // Merge and count
    }
    return inv_count;
}

long long countInversions(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    return mergeSort(arr, temp, 0, n - 1);
}

int main() {
    vector<int> arr = {5, 3, 2, 1, 4};  // Example input
    long long result = countInversions(arr);
    cout << "Number of inversions: " << result << endl;
    return 0;
}
