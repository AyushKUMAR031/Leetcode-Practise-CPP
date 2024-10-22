class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums);
        int n = temp.size();
        for(int i=0;i<temp.size();i++){
            int pos = (i+k)%n;
            nums[pos] = temp[i];
        }
    }
};
