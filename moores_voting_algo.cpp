#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;  // Initialize the result with the smallest possible integer value.
        int sum = 0;  // Initialize the running sum of the subarray.

        // Iterate through the array elements
        for (const int num : nums) {
            // Update the running sum to either start a new subarray (num) or continue adding to the current subarray (sum + num).
            sum = max(num, sum + num);
            
            // Update the answer if the current subarray sum is the largest seen so far.
            ans = max(ans, sum);
        }
        
        // Return the maximum sum found.
        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Call the function and print the result
    int result = solution.maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}

