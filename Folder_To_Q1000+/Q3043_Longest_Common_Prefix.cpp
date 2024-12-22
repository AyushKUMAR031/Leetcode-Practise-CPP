class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> unS;
        for(int i : arr1){
            string a = to_string(i);
            for(int j=1;j<=a.length();j++){
                unS.insert(stoi(a.substr(0, j)));
            }
        }
        int max_length = 0;
        for(int i : arr2){
            string b = to_string(i);
            for(int j=1;j<=b.length();j++){
                int prefix = stoi(b.substr(0,j));
                if(unS.find(prefix) != unS.end()){
                    max_length = max(max_length,j);
                }
            }
        }

        return max_length;
    }
};
