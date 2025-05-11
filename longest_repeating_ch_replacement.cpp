#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26] = {0};  // Frequency count for characters 'A' to 'Z'
        int l = 0, r = 0;    // Sliding window pointers
        int maxFreq = 0;     // Most frequent character count in the window
        int maxLen = 0;      // Maximum length of valid window

        while (r < s.size()) {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            // If more than k characters need replacement, shrink window
            if ((r - l + 1) - maxFreq > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};

// Example usage
int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    int result = sol.characterReplacement(s, k);
    cout << "Length of longest substring after replacement: " << result << endl;
    return 0;
}