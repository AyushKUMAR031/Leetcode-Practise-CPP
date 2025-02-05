class Solution {
public:
    void solve(vector<string> &ans,string temp,int open,int close,int n){
        //base
        if(open == n && close == n){
            ans.push_back(temp);
            return;
        }

        //rr
        if(open < n){
            solve(ans,temp+'(',open+1,close,n);
        }
        if(close < open){
            solve(ans,temp+')',open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string> ans;
        string temp = "";
        solve(ans,temp,open,close,n);
        return ans;
    }
};
