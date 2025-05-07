#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        int l = 0, r = 0;

        // Array to store the last seen index of each character (ASCII size)
        int hash[256];
        fill_n(hash, 256, -1); // Initialize all to -1 (not seen yet)

        while (r < n) {
            // If character has been seen and is inside the current window
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1; // Move the left pointer ahead
            }

            // Calculate current window length and update max
            int len = r - l + 1;
            maxLen = max(maxLen, len);

            // Update last seen index of the character
            hash[s[r]] = r;

            // Expand window
            r++;
        }

        return maxLen;
    }
};

// Optional main function for testing
int main() {
    Solution sol;
    string s = "abcabcbb";
    int result = sol.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;
    return 0;
}
