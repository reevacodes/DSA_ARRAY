#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to count substrings containing at least one 'a', 'b', and 'c'
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;
        int lastSeen[3] = {-1, -1, -1};  // Store last seen positions of 'a', 'b', and 'c'

        for (int i = 0; i < n; ++i) {
            lastSeen[s[i] - 'a'] = i;

            // Check if all characters have been seen at least once
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                count += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }

        return count;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    string input = "abcabc";
    int result = sol.numberOfSubstrings(input);

    cout << "Number of substrings containing all 'a', 'b', and 'c': " << result << endl;
    return 0;
}

