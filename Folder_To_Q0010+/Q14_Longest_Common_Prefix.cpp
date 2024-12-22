class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<char> result;
        string firstString = strs[0];
        for(int i=0;i<firstString.length();i++){
            for(string data : strs){
                if(firstString[i]!=data[i]){
                    string answer(result.begin(), result.end());
                    return answer;
                }
            }
            result.push_back(firstString[i]);
        }
        string answer(result.begin(), result.end());
        return answer;
    }
};
