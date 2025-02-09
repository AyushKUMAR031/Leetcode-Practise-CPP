//1st attempt
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int output=0;
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){

                bool found = false;
                string sub = s.substr(i,j-i);

                for(int k=0;k<sub.length();k++){

                    if(sub[k]==s[j]){
                        found = true;
                        output = max(output,j-i);
                        break;
                    }
                }
                if(found){
                    break;
                }
                else{
                    output = max(output,j-i+1);
                }
            }
        } 
        if(s.length()==1)
        {
            output = 1;
        } 
        return output;
    }
};


//2nd attempt
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int output=0;
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                if(s.substr(i,j-i).find(s[j])!=string::npos){
                    break;
                }
                output=max(output,j-i);
            }
        }
        if(s.empty())
            return 0;
        
        return output+1;
    }   
};

//best - sliding window technique
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int window = 0;
        int l = 0;
        unordered_map<char,int> mp;

        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            mp[c]++;

            while(mp[c] > 1){
                char leftChar = s[l];
                mp[leftChar]--;
                l++;
            }
            window = max(window,r-l+1);
        }
        return window;
    }
};
