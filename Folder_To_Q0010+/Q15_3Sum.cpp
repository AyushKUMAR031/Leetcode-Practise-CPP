class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> unique; //used set to remove duplicates.
        sort(nums.begin(),nums.end()); //sorting for two pointer approach.
        vector<vector<int>> res;

        for(int i=0;i<nums.size()-2;i++){
            int l = i+1;
            int r = nums.size()-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    unique.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                if(sum < 0){
                    l++;
                }
                if(sum > 0){
                    r--;
                }
            }
        }
        for(auto val : unique){
            res.push_back(val);
        }
        return res;
    }
};
