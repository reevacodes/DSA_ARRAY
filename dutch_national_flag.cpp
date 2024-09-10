#include <iostream>
#include <vector>

using namespace std;

void dutchNationalFlag(vector<int>& nums) {
    int low = 0;        // Pointer for 0
    int mid = 0;        // Pointer for 1
    int high = nums.size() - 1;  // Pointer for 2

    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap 0 to the low end and move both low and mid pointers
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            // Leave 1 in the middle and just move the mid pointer
            mid++;
        }
        else {
            // Swap 2 to the high end and move the high pointer
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    // Example usage
    vector<int> nums = {2, 0, 1, 2, 0, 1, 1, 0};

    // Call the function
    dutchNationalFlag(nums);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
