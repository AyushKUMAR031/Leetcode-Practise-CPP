class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int ans;
        long sum = 0;
        for(int value : chalk){
            sum+=value;
        }
        k%=sum; // for reducing the iteration for long inputs.

        for(int i=0;i<chalk.size();i++){
            if(chalk[i]<=k){
                k-=chalk[i];
            }else{
                ans = i;
                break;
            }
        }
        return ans;
    }
};
