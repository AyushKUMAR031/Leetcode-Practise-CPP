class Solution {
public:
    bool isVowel(char x){
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }

    long long atLeastK(string &word, int k){
        unordered_map<char,int> vowel;
        int l = 0;
        long long ans = 0;
        int conso = 0;
        
        for(int r=0;r<word.size();r++){
            if(isVowel(word[r])){
                vowel[word[r]]++;
            }else{
                conso++;
            }

            while( vowel.size() == 5 &&  conso >= k ){
                ans += word.size() - r;
                if(isVowel(word[l])){
                    vowel[word[l]]--;
                    if(vowel[word[l]] == 0){
                        vowel.erase(word[l]);
                    }
                }else{
                    conso--;
                }
                l++;
            }
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word,k) - atLeastK(word,k+1);
    }
};
