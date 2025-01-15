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

//best
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> temp;
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = temp[left].first + temp[right].first;
            if (sum == target) return {temp[left].second, temp[right].second};
            if (sum < target) left++;
            if (sum > target) right--;
        }
        return {}; 
    }
};
