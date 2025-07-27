#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int n = arr1.size();
    int m = arr2.size();

    // Always binary search on the smaller array
    if (n > m) return kthElement(arr2, arr1, k);

    int low = max(0, k - m);
    int high = min(k, n);

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1;
        }
    }

    return -1; // Should never reach here
}

int main() {
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;

    int result = kthElement(arr1, arr2, k);
    cout << "The " << k << "th element is: " << result << endl;

    return 0;
}
