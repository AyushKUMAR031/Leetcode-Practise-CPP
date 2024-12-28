class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp) {
        // base case
        if (n < 0)
            return 0;
        if (n == 0)
            return nums[n];

        if (dp[n] != -1)
            return dp[n];

        int include = solve(nums, n - 2, dp) + nums[n];
        int exclude = solve(nums, n - 1, dp) + 0;

        dp[n] = max(include, exclude);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp1(n, -1); // to exclude last house
        vector<int> dp2(n, -1); // to exclude first house
        int ans1 = solve(nums, n - 2, dp1);
        nums.erase(nums.begin());
        int ans2 = solve(nums, n - 2, dp2);
        return max(ans1,ans2);
    }
};
