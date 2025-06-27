class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<int,int> mp;
        for(int i : word){
            mp[i]++;
        };

        int mindel = INT_MAX;
        for(auto i : mp){
            int x = i.second;
            int del = 0;
            for(auto j : mp){
                int y = j.second;
                if(x+k < y){
                    del += y-x-k;
                }else if( x > y){
                    del += y;
                }
            }
            mindel = min(mindel,del);
        }

        return mindel;
    }
};