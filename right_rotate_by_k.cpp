#include <iostream>
#include <vector>

using namespace std;

// Function to reverse a portion of the array
void reverse(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to right rotate the array by k positions
void rightRotate(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;
    
    // Normalize k if it's greater than the size of the array
    k = k % n;

    // Reverse the last k elements
    reverse(arr, n - k, n - 1);

    // Reverse the first n-k elements
    reverse(arr, 0, n - k - 1);

    // Reverse the entire array
    reverse(arr, 0, n - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    rightRotate(arr, k);

    cout << "Array after right rotation by " << k << " positions: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
