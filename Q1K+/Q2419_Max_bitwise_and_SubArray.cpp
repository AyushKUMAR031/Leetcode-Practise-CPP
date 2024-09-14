class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_num = nums[0];
        for(int i=0;i<nums.size();i++){
            max_num = max(max_num,nums[i]);          
        }
        int max_length = 0;
        int length = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==max_num){
                length++;
                max_length = max(length,max_length);
            }else{
                length = 0;
            }
        }
        return max_length;
    }
};
