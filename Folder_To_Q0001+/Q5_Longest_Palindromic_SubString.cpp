class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;

        string res = "";

        for(int i=0;i<s.size();i++){

            //for odd length 1,3,5 
            //cause we are moving both left and right pointer.
            int l = i,r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
            }

            //using current l and r to get substring
            if ((r - l - 1) > res.size()) {
                res = s.substr(l + 1, r - l - 1);
            }

            //for even length , same thing but we start l at i-1 and r at i to make a even length
            l = i-1;
            r = i;

            while(l >= 0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
            }
            
            if ((r - l - 1) > res.size()) {
                res = s.substr(l + 1, r - l - 1);
            }

        }
        
        return res;
    }
};