class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int lastIndex = digits.size()-1;
        if(digits[lastIndex]==9){
            digits[lastIndex]=0;
            carry=1;
            int i;
            for(i=lastIndex-1;i>=0;i--){
                if(digits[i]==9){
                    digits[i]=0;
                    carry=1;
                }else{
                    digits[i]++;
                    carry=0;
                    break;
                }
            }
            if(carry==1){
                digits.insert(digits.begin(),1);
            }
        }else{
            digits[lastIndex]++;
        }
        return digits;
    }
};
