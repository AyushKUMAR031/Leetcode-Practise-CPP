class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int profit = 0;
        int highestPrice = INT_MIN;
        int n = prices.size() - 1;
        while(n>=0){
            if(highestPrice > prices[n]){
               profit = highestPrice - prices[n];
               maxprofit += profit;
               highestPrice = prices[n]; 
            }
            highestPrice = max(highestPrice,prices[n]);
            n--;
        }
        return maxprofit;
    }
};
/*
Initially, I thought of iterating backward, similar toBest Time to Buy and Sell Stock 1, where I tracked the highest price.
But here, since multiple transactions are allowed, I realized that instead of tracking only one max profit, I needed to sum up every profitable transaction.;P
So, I focused on adding profits whenever there was an increase in price. 😎
*/
