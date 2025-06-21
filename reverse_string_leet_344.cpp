#include <iostream>
#include <vector>
#include <algorithm> // for swap

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

// Optional: main function to test the code
int main() {
    Solution sol;
    vector<char> input = {'h', 'e', 'l', 'l', 'o'};
    
    cout << "Original string: ";
    for (char c : input) cout << c;
    cout << endl;

    sol.reverseString(input);

    cout << "Reversed string: ";
    for (char c : input) cout << c;
    cout << endl;

    return 0;
}
