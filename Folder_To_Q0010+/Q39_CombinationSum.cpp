//using Take and Not Take technique. but beats 60%
class Solution {
public:
    void solve(vector<int> &candidates, vector<vector<int>> &ans,vector<int> &temp, int target,int start,int size){
        //base case : when the target gets 0 return
        if(target == 0 ){
            ans.push_back(temp);
            return;
        }

        //checking cases for negative target and what if we iterate over the size.
        if(target < 0 || start >= size){
            return;
        }

        //rr {take - not Take}
        //not Take
        solve(candidates,ans,temp,target,start+1,size);

        //Take
        temp.push_back(candidates[start]);
        solve(candidates,ans,temp,target-candidates[start],start,size);

        //backtracking to pop the last inserted candidate in temp.
        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int size = candidates.size();
        int start = 0;

        //STEP-1 : setting up the 2d vector for storing  valid results.
        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, ans, temp, target, start, size);

        return ans;
    }
};


//best or real technique.
