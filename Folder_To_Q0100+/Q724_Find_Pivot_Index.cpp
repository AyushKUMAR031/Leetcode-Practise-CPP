class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, n = nums.size() - 1;
        vector<int> prefix(n+1);
        for(int i = 0;i<=n;i++){
            sum += nums[i];
            prefix[i] = sum;
        }
        int i = 0;
        while(i<=n){
            if( i == 0){
                if(prefix[n]-prefix[i] == 0)
                    return 0;
            }else{
                if(prefix[n]-prefix[i] == prefix[i-1])
                    return i;
            }
            i++;
        }
        return -1;
    }
};
