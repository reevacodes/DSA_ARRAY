#include <iostream>
#include <string>
#include <climits>
using namespace std;

/*
    Problem: Minimum Window Substring (LeetCode)
    Given two strings s and t, return the minimum window in s which will contain all the characters in t.
    If there is no such window, return the empty string "".
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        // Edge case: t is longer than s
        if (n > m) return "";

        // Frequency map for characters in t
        int hash[128] = {0};
        for (char c : t) {
            hash[c]++;
        }

        // Frequency map for current window in s
        int freq[128] = {0};
        int count = n; // Number of characters still needed

        int l = 0, r = 0;
        int minLen = INT_MAX;
        int startIndex = 0;

        while (r < m) {
            freq[s[r]]++;

            // Decrease count if this character is needed and still within required frequency
            if (hash[s[r]] > 0 && freq[s[r]] <= hash[s[r]]) {
                count--;
            }

            // Try shrinking the window from the left
            while (count == 0) {
                // Update the minimum window length
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                // Remove the left character from window
                freq[s[l]]--;
                if (hash[s[l]] > 0 && freq[s[l]] < hash[s[l]]) {
                    count++;
                }
                l++;
            }

            r++;
        }

        // Return result
        if (minLen == INT_MAX) {
            return "";
        } else {
            return s.substr(startIndex, minLen);
        }
    }
};

// Example usage
int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window substring: " << sol.minWindow(s, t) << endl;
    return 0;
}
