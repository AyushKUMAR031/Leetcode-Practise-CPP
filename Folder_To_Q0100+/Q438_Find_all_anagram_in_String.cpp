class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) return ans;

        unordered_map<char, pair<int, int>> mp;

        for (char c : p) {
            mp[c].first++;
        }

        int l = 0, r = 0;
        int w = p.size();

        while(r < s.size()){
            char c = s[r];

            if (mp.count(c)){
                mp[c].second++;

                while (mp[c].second > mp[c].first) {
                    if (mp.count(s[l])) {
                        mp[s[l]].second--;
                    }
                    l++;
                }

            }else {
                // Not a valid character → reset window
                while (l <= r) {
                    if (mp.count(s[l])) mp[s[l]].second--;
                    l++;
                }
            }

           if (r - l + 1 == w) {
                ans.push_back(l);
                if (mp.count(s[l])) 
                    mp[s[l]].second--;
                l++;
            }

            r++;
        }
        return ans;
    }
};