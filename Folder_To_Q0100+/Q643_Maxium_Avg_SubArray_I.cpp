//best - 100% BEATS
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0;
        int r = k-1;
        double sum = 0;

        for(int i = 0; i <= r ; i++){
            sum += nums[i];
        }
        double maxAvg = INT_MIN;

        while( r < nums.size()){
            double avg = sum / k;
            maxAvg = max(maxAvg , avg);

            sum -= nums[l];
            l++;

            if(r+1 <= nums.size()-1){
                sum += nums[r+1];
            }
            r++;
        }
        return maxAvg;
    }
};
