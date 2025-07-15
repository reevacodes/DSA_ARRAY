#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int floorVal = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return arr[mid]; // exact match is the floor
        else if (arr[mid] < x) {
            floorVal = arr[mid]; // possible floor
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return floorVal;
}

int findCeil(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ceilVal = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return arr[mid]; // exact match is the ceil
        else if (arr[mid] > x) {
            ceilVal = arr[mid]; // possible ceil
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ceilVal;
}

int main() {
    vector<int> arr = {1, 2, 4, 6, 10};
    int x = 5;

    int floorValue = findFloor(arr, x);
    int ceilValue = findCeil(arr, x);

    if (floorValue != -1)
        cout << "Floor of " << x << " is: " << floorValue << endl;
    else
        cout << "No floor found for " << x << endl;

    if (ceilValue != -1)
        cout << "Ceil of " << x << " is: " << ceilValue << endl;
    else
        cout << "No ceil found for " << x << endl;

    return 0;
}
