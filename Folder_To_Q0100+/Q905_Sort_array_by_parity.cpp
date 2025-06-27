class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> temp;
        for(int i=0;i<nums.size();){
            if(nums[i]%2 != 0){
                temp.push_back(nums[i]);
                nums.erase(nums.begin()+i);
            }
            else i++;
        }

        for(int i : temp){
            nums.push_back(i);
        }
        return nums;
    }
};