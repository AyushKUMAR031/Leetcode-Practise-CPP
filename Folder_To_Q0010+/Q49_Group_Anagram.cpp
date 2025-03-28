//my own answer

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy(strs);
        for(int i=0;i<copy.size();i++){
            sort(copy[i].begin(),copy[i].end());
        }

        unordered_map<string,vector<int>> calc;
        for(int i=0;i<copy.size();i++){
            calc[copy[i]].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto i : calc){
            vector<string> arr;
            for(int index : i.second){
                arr.push_back(strs[index]);
            }
            ans.push_back(arr);
        }

        return ans;
    }
};
