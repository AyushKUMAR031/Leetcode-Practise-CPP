class Solution {
public:
    long long minimumSteps(string s) {
        long long int swap_req = 0;
        int right_zero = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == '0'){
                right_zero++;
            }else{
                if(right_zero > 0){
                    int j = i;
                    swap(s[j],s[j+right_zero]);
                    swap_req += right_zero;
                }
            }
        }
        return swap_req;
    }
};
