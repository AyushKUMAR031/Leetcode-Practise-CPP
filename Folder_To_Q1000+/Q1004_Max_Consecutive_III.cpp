//it is of O(N^2) so we get tle - Brute Force.
class Solution {
public:
    //think it of as longest subarray with atmost k zeros.
    int longestOnes(vector<int>& nums, int k) {
        int maxlength = 0;
        for(int i = 0;i<nums.size();i++){
            int zero = 0;
            for(int j = i;j<nums.size();j++){
                if(nums[j] == 0){
                    zero++;
                }

                if(zero <= k){
                    int length = j-i + 1;
                    maxlength = max(maxlength,length);
                }

                if(zero > k){
                    break;
                }
            }
        }
        return maxlength;
    }
};

//sliding window
class Solution {
public:
    //think it of as longest subarray with atmost k zeros.
    int longestOnes(vector<int>& nums, int k) {
        int maxlength = 0;
        int l = 0;
        int r = 0;
        int zero = 0;
        while(r < nums.size()){
            if(nums[r] == 0){
                zero++;
            }

            while(zero > k){
                if(nums[l] == 0){
                    zero--;
                }
                l++;
            }

            int length = r-l+1;
            maxlength = max(maxlength,length);
            r++;
        }
        return maxlength;
    }
};
