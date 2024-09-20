class Solution {
public:
    bool isPalindrome(string s) {
        bool isPalin = true;
        string temp = "";
        for(char i : s){
          if(isalnum(i)){
            temp += tolower(i);
          }
        }
        int left = 0;
        int right = temp.size()-1;
        while(left<right){
            if(temp[left] != temp[right]){
                isPalin = false; 
                break;               ;
            }
            left++;
            right--;
        }
        return isPalin;
    }
};

//me pro
