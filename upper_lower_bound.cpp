#include <iostream>
#include <vector>
using namespace std;

// Function to find the lower bound (first index where arr[i] >= target)
int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size();
    int ans = arr.size();  // default if not found

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Function to find the upper bound (first index where arr[i] > target)
int upperBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size();
    int ans = arr.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target) {
            ans = mid;
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 5, 6};
    int target = 4;

    int lb = lowerBound(arr, target);
    int ub = upperBound(arr, target);

    cout << "Lower Bound of " << target << " is at index: " << lb << endl;
    cout << "Upper Bound of " << target << " is at index: " << ub << endl;

    return 0;
}
