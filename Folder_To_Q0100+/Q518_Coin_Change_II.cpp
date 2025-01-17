class Solution {
public:
    int solve(int start,int amount, vector<int>& coins,int n,vector<vector<int>>& dp){
        //base
        if(amount == 0) return 1;
        if(amount < 0 || start>= n) return 0;

        //step-2 
        if(dp[start][amount] != -1) return dp[start][amount];

        //recursion {take -- not take}
        int notTake = solve(start+1,amount,coins,n,dp);
        int take = solve(start,amount-coins[start],coins,n,dp);

        //step-3 updating
        return dp[start][amount] = take + notTake;

    }
    int change(int amount, vector<int>& coins) {
        int start = 0;
        int n = coins.size();
        //step-1
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(start,amount,coins,n,dp);
    }
};
