//ok
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]) {
                ans.push_back(nums[i]);
                i++;
            }
        }
        return ans;
    }
};


//better
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        vector<int> res;
        for (int i : nums) {
            if (ans[i - 1] == 0) {
                ans[i - 1] = -1;
            } else {
                ans[i - 1] = 1;
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i] == 1) res.push_back(i+1);
        }
        return res;
    }
};
