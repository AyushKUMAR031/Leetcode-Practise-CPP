//1st method Beats -15%
class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1)
            return '0';

        string s = "0";
        
        for(int i=2;i<=n;i++){
            string temp = s;
            for(int j=0;j<temp.length();j++){
                if(temp[j] == '0'){
                    temp[j] = '1';
                }else{
                    temp[j] = '0';
                }
            }
            reverse(temp.begin(),temp.end());
            s = s + '1' + temp;
        }

        return s[k-1];
    }
};

//alteration to reduce time complexity {{Beats -> 45%}}
class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1)
            return '0';

        string s = "0";
        
        for(int i=2;i<=n && k>s.length();i++){
            string temp = s;
            for(int j=0;j<temp.length();j++){
                if(temp[j] == '0'){
                    temp[j] = '1';
                }else{
                    temp[j] = '0';
                }
            }
            reverse(temp.begin(),temp.end());
            s = s + '1' + temp;
        }

        return s[k-1];
    }
};

//best solution
// ?? in editorials
