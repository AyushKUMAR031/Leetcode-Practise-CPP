class Solution {
public:
    int solve(vector<int> &nums,int target,vector<int> &dp){
        //base case
        if(target < 0) return 0;
        if(target == 0) return 1; 

        //rr
        //DP STEP-3
        if(dp[target] != -1){
            return dp[target];
        }

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += solve(nums,target-nums[i],dp);
        }
        
        //DP STEP-2
        dp[target] = ans;
        return dp[target];

    }
    int combinationSum4(vector<int>& nums, int target) {
        //STEP-1 creating DP
        vector<int> dp(target+1,-1);
        return solve(nums,target,dp);
    }
};
