class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string temp = "";
        for(char ch : s){
            temp += ch;
            if(temp.size() == k){
                ans.push_back(temp);
                temp = "";
            }
        }
        if(temp.size() > 0){
            while(temp.size() != k){
                temp += fill;
            }
            ans.push_back(temp);
            temp = "";
        }

        return ans;
    }
};