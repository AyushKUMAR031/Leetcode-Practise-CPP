class Solution {
private:
    void solve(vector<int> nums,vector<vector<int>>& ans,int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            solve(nums,ans,index+1);
            //backtrack
            swap(nums[index],nums[j]);//to restore the original array state after coming back
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};
