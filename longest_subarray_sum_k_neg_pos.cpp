#include <bits/stdc++.h> 
using namespace std;

int getLongestSubarray(vector<int>& nums, int k) {
    map<long long, int> preSumMap;  // Map to store the prefix sum and its earliest index
    long long sum = 0;              // Variable to store the running sum of elements
    int maxLen = 0;                 // Variable to store the maximum length of subarray with sum k

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];  // Add current element to the running sum

        // Check if the sum of elements from the start to the current index equals k
        if (sum == k) {
            maxLen = max(maxLen, i + 1);  // Update maxLen to the current subarray length
        }

        long long rem = sum - k;  // Calculate the remaining sum needed to reach k

        // Check if this remaining sum has been seen before
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];  // Calculate the length of the subarray with sum k
            maxLen = max(maxLen, len);     // Update maxLen if this subarray is longer
        }

        // Insert the current sum into the map only if it hasn't been seen before
        // This ensures that we keep the earliest occurrence of each sum
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;  // Return the maximum length of subarray with sum k
}

int main() {
    vector<int> nums = {-1, 0, 1, 1, -1, -1, 0};  // Example input array
    int k = 0;  // Target sum
    cout << "Length of the longest subarray: " << getLongestSubarray(nums, k) << endl;
    return 0;
}
