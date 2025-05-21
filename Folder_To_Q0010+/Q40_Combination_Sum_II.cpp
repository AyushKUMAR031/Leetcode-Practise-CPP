class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &temp,int start){
        //base
        if(target == 0){
            ans.push_back(temp);
            return;
        } 

        if(target < 0){
            return;
        }

        for(int i=start;i<candidates.size();i++){

            if(i > start && candidates[i] == candidates[i-1]) continue; //skipping dups
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,temp,i+1); // with i+1 not choosing same index again (max once)
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,ans,temp,0);
        return ans;
    }
};
