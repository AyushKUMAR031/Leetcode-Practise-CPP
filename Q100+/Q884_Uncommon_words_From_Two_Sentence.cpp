//my method the best method
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> words;
        vector <string> uncommon_words;
        string temp ="";
        for(auto i : s1){
            if(i != ' ')
                temp += i;
            else{
                if(words.find(temp) != words.end()){
                    words[temp]++;
                }else{
                    words[temp] = 1;
                }
                temp = "";
            }
        }

        if(words.find(temp) != words.end()){
            words[temp]++;
        }else{
            words[temp] = 1;
        }
        temp = "";

        for(auto i : s2){
            if(i != ' ')
                temp += i;
            else{
                if(words.find(temp) != words.end()){
                    words[temp]++;
                }else{
                    words[temp] = 1;
                }
                temp = "";
            }
        }

        if(words.find(temp) != words.end()){
            words[temp]++;
        }else{
            words[temp] = 1;
        }
        temp = "";

        for (auto& pair : words) {
            if (pair.second == 1) {
                uncommon_words.push_back(pair.first);
            }
        }

        return uncommon_words;
    }   
};
