class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};

//better
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> prefix;
        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            if(prefix.find(diff) != prefix.end()){
                return {i,prefix[diff]};
            }else{
                prefix[nums[i]] = i;
            }
        }
        return {};
    }
};
