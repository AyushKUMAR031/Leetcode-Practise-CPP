class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlength = 0;
        int l = 0;
        int r = 0;
        int maxVal = INT_MIN;
        unordered_map<char,int> mp;


        while(r < s.size()){
            mp[s[r]]++; 

            if(mp[s[r]] > maxVal){
                maxVal = mp[s[r]];
            }

            int currentLength = r - l + 1;

            if(currentLength - maxVal > k ){
                mp[s[l]]--;
                l++;
            }

            if(currentLength - maxVal <= k){
                maxlength = max(maxlength,currentLength);
            }
            r++;
        }

        return maxlength;
    }
};
