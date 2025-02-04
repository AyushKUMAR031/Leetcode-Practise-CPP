class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign = 1;
        long long ans = 0;
        while(s[i] == ' ' && i<s.size()){ //removing leading whitespace.
            i++;
        }

        if(s[i] == '-'){ //handling signs
            sign = -1;
            i++;
        }else if(s[i] == '+'){
            i++;
        }

        while(i<s.size()){
            if(isdigit(s[i])){
                ans = ans*10 + (s[i]-'0');

                //checking overflow
                if(ans > INT_MAX && sign == -1){
                    return INT_MIN;
                }else if(ans < INT_MIN && sign == 1){
                    return INT_MAX;
                }else if(ans > INT_MAX && sign == 1){
                    return INT_MAX;
                }
                
                i++;
            }else{
                break;
            }
        }
        return ans*sign;
    }

};
