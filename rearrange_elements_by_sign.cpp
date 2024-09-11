#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);  // Create a new vector to store the rearranged elements
        int posIndex = 0;       // Index for placing positive numbers at even indices
        int negIndex = 1;       // Index for placing negative numbers at odd indices

        // Iterate through the original array
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                // If the number is negative, place it at the next available odd index
                ans[negIndex] = nums[i];
                negIndex += 2;
            } else {
                // If the number is positive, place it at the next available even index
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }

        return ans;  // Return the rearranged array
    }
};

int main() {
    // Example input array
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    // Create an instance of the Solution class
    Solution solution;

    // Call the rearrangeArray function
    vector<int> result = solution.rearrangeArray(nums);

    // Output the result
    cout << "Rearranged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
