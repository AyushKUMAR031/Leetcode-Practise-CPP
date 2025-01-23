class Solution {
public:
    int BS(vector<int>& nums, int target,int s, int e){
        while(s<=e){
            int m = s + (e-s)/2;
            if(nums[m] == target){
                return m;
            }else if(target < nums[m]){
                e = m - 1;
            }else{
                s = m + 1;
            }
        }
        return -1;
    }
    int getPivot(vector<int>& nums){
        int s = 0, e = nums.size() - 1;
        int m = s + (e-s)/2;
        while(s<e){
            m = s + (e-s)/2;
            if(nums[m]>nums[e]){
                s = m + 1;
            }else{
                e = m;
            }
        }
        return s;
    }
    int search(vector<int>& nums, int target) {
        if (nums.empty()) { 
            return -1; 
        }
        int pivot = getPivot(nums);

        int e = nums.size() - 1;

        if(target>=nums[pivot] && target <= nums[e]){
            return BS(nums,target,pivot,e);
        }
        return BS(nums,target,0,pivot-1);
    }
};
