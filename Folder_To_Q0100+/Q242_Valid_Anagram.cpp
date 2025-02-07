//first
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};


//second
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }

        for(char c : t){
            if(mp[c]){
                mp[c]--;
            }else{
                return false;
            }
        }

        for(auto i : mp){
            if(i.second != 0){
                return false;
            }
        }
        return true;
    }
};


//best
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }

        for(char c : t){
            mp[c]--;
            if(mp[c] < 0){
                return false;
            }
        }
        
        return true;
    }
};
