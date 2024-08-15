#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();

    while (right < n) {
        // If the current sum exceeds the target, move the left pointer to reduce the sum
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // Check if the current sum matches the target
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move the right pointer to include more elements in the current window
        right++;
        if (right < n) {
            sum += a[right];
        }
    }

    return maxLen;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    long long k = 9;
    cout << "The length of the longest subarray with sum " << k << " is: " 
         << longestSubarrayWithSumK(a, k) << endl;
    return 0;
}
