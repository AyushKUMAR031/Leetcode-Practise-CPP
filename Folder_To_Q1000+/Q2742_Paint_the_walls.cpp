class Solution {
public:
    //think of this question as if a wall is to be painted by a paid painter or not.
    int solve(vector<int>& cost, vector<int>& time,int index,int walltopaint,vector<vector<int>>& dp){
        //base case : all walls painted
        if(walltopaint <=0)
            return 0;
        //?? no more painters to choose
        if(index < 0)
            return 1e9;

        if(dp[index][walltopaint] != -1){
            return dp[index][walltopaint];
        }

        int include = cost[index] + solve(cost,time,index-1,(walltopaint-1)-time[index],dp);
        int exclude = 0 + solve(cost,time,index-1,walltopaint,dp);

        dp[index][walltopaint] = min(include,exclude);
        return dp[index][walltopaint];
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(cost,time,n-1,time.size(),dp); 
    }
};