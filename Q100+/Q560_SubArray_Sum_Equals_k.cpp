//my method {{brute force}} time taken - 2080ms
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = nums[i];
            if(sum == k){
                count++;
            }
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};

//best method
// ???
