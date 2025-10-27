#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            // Update minimum price seen so far
            minPrice = min(minPrice, prices[i]);
            // Calculate profit if we sell at current price
            int profit = prices[i] - minPrice;
            // Update maximum profit
            maxProfit = max(maxProfit, profit);
        }
        
        return maxProfit;
    }
};

// Example usage
int main() {
    Solution solution;
    
    // Example 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Example 1: prices = [7,1,5,3,6,4]" << endl;
    cout << "Output: " << solution.maxProfit(prices1) << endl;
    cout << "Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5" << endl << endl;
    
    // Example 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Example 2: prices = [7,6,4,3,1]" << endl;
    cout << "Output: " << solution.maxProfit(prices2) << endl;
    cout << "Explanation: No transactions are done and the max profit = 0" << endl;
    
    return 0;
}
