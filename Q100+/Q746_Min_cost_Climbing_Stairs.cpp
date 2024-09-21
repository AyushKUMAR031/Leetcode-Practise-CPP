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

//dp tabulation bottom-up approach
class Solution {
public:
    //Tabluation 
    int solve(vector<int> &cost,int n){
        vector<int> dp(n+1);
        //base case
        dp[0] = cost[0];
        dp[1] = cost[1];

        //step 3
        for(int i=2;i<n;i++){
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        return min(dp[n-1],dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = solve(cost,n);
        return ans;
    }
};

//space optimization
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //base case
        int prev1 = cost[0];
        int prev2 = cost[1];
        int curr;
        //step 1
        for(int i=2;i<n;i++){
            curr = min(prev1,prev2) + cost[i];
            prev1 = prev2;
            prev2 = curr;
        }
        return min(prev1,prev2);
    }
};
