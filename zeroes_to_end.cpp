#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int j = 0; // Pointer to track the position of the next non-zero element

    // Traverse the array and move non-zero elements to the front
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }

    // Fill the remaining positions with zeroes
    while (j < nums.size()) {
        nums[j] = 0;
        j++;
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    cout << "Array after moving zeroes to the end: ";
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}
