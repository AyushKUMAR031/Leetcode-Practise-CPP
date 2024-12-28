class Solution {
public:
    int solve(vector<int>& nums,int i,int n,vector<int>& dp){
        //base case
        if(i>n) return 0;
        if(i == n) return nums[n];

        //step 2 memo
        if(dp[i] != -1)
            return dp[i];

        //recursive
        int include = solve(nums,i+2,n,dp) + nums[i];
        int exclude = solve(nums,i+1,n,dp) + 0;

        dp[i] = max(include,exclude);//step 3 memo
        return dp[i];

    }
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+1,-1); //step 1 memo
        return solve(nums,0,n,dp);
    }
};
