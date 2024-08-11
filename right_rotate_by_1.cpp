#include <iostream>
#include <vector>

using namespace std;

void rightRotateByOne(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return;

    // Store the last element
    int last = arr[n - 1];

    // Shift all elements to the right
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    // Place the last element at the first position
    arr[0] = last;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    rightRotateByOne(arr);

    cout << "Array after right rotation by 1: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
