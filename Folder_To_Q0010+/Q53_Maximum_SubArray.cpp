class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = nums[0];
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            maxSum = max(maxSum,sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};

//best
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN; //changed to int_min from nums[i].
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            maxSum = max(maxSum,sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};
