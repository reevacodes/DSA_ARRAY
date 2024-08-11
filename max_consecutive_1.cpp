#include <iostream>
#include <vector>
using namespace std;

int consecutiveOnes(vector<int>& arr) {
    if (arr.empty()) return 0; // Edge case: if the array is empty, return 0

    int count = 0, max = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            count++;  // Increment count for consecutive 1s
        } else {
            // When a 0 is encountered, update max if needed and reset count
            if (count > max) {
                max = count;
            }
            count = 0;  // Reset count
        }
    }
    
    // Final check to update max in case the array ends with consecutive 1s
    if (count > max) {
        max = count;
    }
    
    return max;
}

int main() {
    vector<int> arr = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    
    int result = consecutiveOnes(arr);
    cout << "The maximum number of consecutive 1s is: " << result << endl;

    return 0;
}
