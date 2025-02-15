class Solution {
private:
    int logic(vector<int>&nums,int goal){
        if(goal < 0) return 0;    //checking if the goal is negative
        int l = 0;
        int r = 0;
        int sum = 0;
        int count = 0;
        while(r < nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            count += r-l+1; //We're adding the length of each subarray in our count.
            //whenever the sum is lesser than or equal to goal(passed on value of goal)
            r++;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return logic(nums,goal) - logic(nums,goal-1); //value for sum == goal , can be calculate by (sum <= goal) - (sum <=goal - 1);
    }
};
