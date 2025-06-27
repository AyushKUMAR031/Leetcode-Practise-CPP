class Solution {
public:
    int solve(string &text1,string &text2,int i,int j,vector<vector<int>> &dp){
        //base
        if(i==text1.size()) return 0;
        if(j==text2.size()) return 0;

        if(dp[i][j] != -1){ //step-3
            return dp[i][j];
        }
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + solve(text1,text2,i+1,j+1,dp);
        }else{
            ans = max(solve(text1,text2,i,j+1,dp),solve(text1,text2,i+1,j,dp));
        }

        return dp[i][j] = ans; //step-2
    }
    int longestCommonSubsequence(string text1, string text2) {
        //since two params are changing i,j its 2-d dp
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));//step-1
        return solve(text1,text2,0,0,dp);
    }
};