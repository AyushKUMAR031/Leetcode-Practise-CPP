//dp recursive approach top-down
class Solution {
public:
    int solve(vector<int> &cost,int n,vector<int> &dp){
        //base case
        if(n <= 1)
            return cost[n];
            
        //step 3
        if(dp[n] != -1)
            return dp[n];

        //recursive
        //step 2
        dp[n] = cost[n] + min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //memoization
        //step 1
        vector<int> dp(n+1,-1);
        int ans = min(solve(cost,n-1,dp),solve(cost,n-2,dp)); 
        //we will not take nth stair cost i.e one loop of min is written outside
        return ans;
    }
};
