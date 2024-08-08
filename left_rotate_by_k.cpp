#include <iostream>
#include <vector>

using namespace std;

void rotateArrayLeft(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;  // Ensure k is within the bounds of the array size

    // Step 1: Store the first k elements in a temporary vector
    vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    // Step 2: Shift the remaining elements to the left
    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }

    // Step 3: Place the elements from temp at the end of the array
    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the number of positions to rotate: ";
    cin >> k;

    // Perform the left rotation
    rotateArrayLeft(arr, k);

    // Print the rotated array
    cout << "Array after rotation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
