//best better than aman
//itachi uchiha
class Solution {
public:
    bool check(vector<int>& nums) {
       vector<int> a(nums);
       sort(a.begin(), a.end());
       bool sr_flag;
       int x = 0;

       while(x<a.size()){
            sr_flag = true;
            for(int i=0;i<a.size();i++){
                if(a[i] != nums[(i+x) % a.size()]){
                    sr_flag = false;
                }
                if(!sr_flag){
                    break;
                }
            }
            if(sr_flag){
                return true;
            }
        x++;
       }
       return false;
    }
};
