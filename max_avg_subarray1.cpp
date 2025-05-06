#include <iostream>
#include <vector>
#include <climits>      // For INT_MIN

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        // Initial window sum of first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        // Slide the window
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];  // Add new, remove old
            maxSum = max(maxSum, sum);     // Update max
        }

        return (double)maxSum / k;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    // Find max average of subarray of size k
    double result = sol.findMaxAverage(nums, k);

    // Output result without precision control
    cout << "Maximum average of subarray of size " << k << " is: " << result << endl;

    return 0;
}
