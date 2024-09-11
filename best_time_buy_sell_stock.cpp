#include <iostream>
#include <vector>
#include <algorithm>  // For using the min() and max() functions

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize variables to store maximum profit and the minimum price
        int maxProfit = 0;
        int n = prices.size();
        int mini = prices[0];  // Minimum price to buy the stock

        // Loop through each price in the vector
        for (int i = 0; i < n; i++) {
            // Calculate the profit if we sell at the current price
            int cost = prices[i] - mini;
            // Update maxProfit if we get a higher profit
            maxProfit = max(cost, maxProfit);
            // Update the minimum price for future comparisons
            mini = min(mini, prices[i]);
        }

        // Return the maximum profit found
        return maxProfit;
    }
};

int main() {
    // Example input
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    // Create an instance of the Solution class
    Solution solution;
    
    // Call the maxProfit function and store the result
    int result = solution.maxProfit(prices);
    
    // Output the result
    cout << "Maximum profit: " << result << endl;

    return 0;
}
