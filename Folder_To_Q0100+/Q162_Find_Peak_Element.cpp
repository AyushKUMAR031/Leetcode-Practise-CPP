class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0 , e = nums.size() -1, m = s + (e-s)/2;
        while(s<=e){
            if(m-1>=0 && nums[m-1] > nums[m]){
                e = m - 1;
            }else if(m+1<=nums.size()-1 && nums[m+1] > nums[m]){
                s = m + 1;
            }else{
                return m;
            }
            m = s + ( e - s )/2;
        }
        return 0;
    }
};
