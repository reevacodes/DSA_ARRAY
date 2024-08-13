#include <vector>
#include <iostream>
using namespace std;

int singleNumber(const vector<int>& nums) {
    int result = 0;
    for(int num : nums) {
        result ^= num;  // XOR all numbers
    }
    return result;  // The result will be the number that appears only once
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = singleNumber(nums);
    
    // Output the result
    cout << "The number that appears once is: " << result << endl;
    return 0;
}

