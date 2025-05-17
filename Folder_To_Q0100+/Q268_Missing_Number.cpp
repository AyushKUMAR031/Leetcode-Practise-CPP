//first thought
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i != nums[i]) return i;
        }
        return nums.size();
    }
};



//BEATS 100% using xor
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0 , xor2 = 0;
        for(int i=0;i<nums.size();i++){
            xor1^= i;
            xor2^= nums[i];
        }
        xor1^=nums.size();

        return xor1^xor2;
    }
};
