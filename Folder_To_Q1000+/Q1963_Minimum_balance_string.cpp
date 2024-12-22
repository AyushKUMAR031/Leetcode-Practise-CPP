class Solution {
public:
    int minSwaps(string s) {
        int size = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '[')
                size++;
            else if (size > 0) 
                size--;
        }
        return (size + 1) / 2;
    }
};


//method 2
class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0;
        for(char ch : s){
            if(ch == ']'){
                if(imbalance == 0){
                    imbalance++;
                }else{
                    imbalance--;
                }
            }else{
                imbalance++;
            }
        }
        return (imbalance + 1)/2;
    }
};
