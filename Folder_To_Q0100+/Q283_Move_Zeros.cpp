class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();){
            if(nums[i]==0){
                count++;
                nums.erase(nums.begin()+i);
            }
            else i++;
        }

        nums.resize(nums.size()+count,0);
    }
};