//best 100%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() - 1;
        int highestPrice = INT_MIN;
        int profit = 0;
        int maxprofit = 0;

        while (n >= 0) {
            if (highestPrice > prices[n]) {
                profit = highestPrice - prices[n];
                maxprofit = max(maxprofit, profit);
            }
            highestPrice = max(highestPrice, prices[n]);
            n--;
        }
        return maxprofit;
    }
};
