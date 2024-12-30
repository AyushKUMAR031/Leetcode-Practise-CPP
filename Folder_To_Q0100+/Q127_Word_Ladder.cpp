class Solution {
public:
    int ladderLength(string beginWord, string endWord,vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());

        if (set.find(endWord) == set.end()) return 0;

        queue<string> q;
        q.push(beginWord);

        int change = 1;

        while (!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++){
                string curr = q.front();
                q.pop();

                if(curr == endWord) return change; //base case to stop

                //changing each char in the curr and matching it with set to push in queue
                for(int j=0;j<curr.length();j++){
                    char original = curr[j];
                    for(char ch='a';ch<='z';ch++){
                        if(ch == original) continue;
                        curr[j] = ch;
                        if(set.find(curr) != set.end()){
                            q.push(curr);
                            set.erase(curr);
                        }
                    }
                    //restore original char
                    curr[j] = original;
                }
            }
            change++;   
        }
        return 0;
    }
};
