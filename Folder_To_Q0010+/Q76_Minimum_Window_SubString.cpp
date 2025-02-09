class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char , pair<int,int> > mp;

        for(char ch : t){
            mp[ch].first++; // storing the required occurence of chars.
        }

        int l = 0;
        int r = 0;
        int minLength = INT_MAX;
        int startingIndex = 0;
        int reqSize = mp.size();
        int formedSize = 0;

        while(r < s.size()){
            char ch = s[r];
            if(mp.find(ch) != mp.end()){
                mp[ch].second++;

                if(mp[ch].first == mp[ch].second){
                    formedSize++;
                }
            }

            while(formedSize == reqSize){
                //updating minLength if any and startingIndex.
                if(r - l + 1 < minLength){
                    minLength = r-l+1;
                    startingIndex = l;
                }

                char leftChar = s[l];
                if(mp.find(leftChar) != mp.end()){
                    mp[leftChar].second--;

                    //checking if formation is destroyed or not
                    if(mp[leftChar].second < mp[leftChar].first){
                        formedSize--;
                    }

                }   
                l++;
            }
            r++;
        }
        return minLength == INT_MAX ? "" : s.substr(startingIndex,minLength);
    }
};
