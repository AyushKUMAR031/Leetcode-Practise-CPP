//my method
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); //for faster input and output operation

        int count = 0;
        for(string s : words){
            bool string_consistent = true;
            for(char c : s){
                if(allowed.find(c) == string :: npos){
                    string_consistent = false;
                    break;
                }
            }
            if(string_consistent){
                count++;
            }
        }
        return count;
    }
};

//ritesh method
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

        unordered_map<char, int> mp;

        for (auto i : allowed)
            mp[i] = 1;

        int ans = words.size();

        for (auto i : words) {
            for (auto j : i) {
                if (mp[j] == 0) {
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};
