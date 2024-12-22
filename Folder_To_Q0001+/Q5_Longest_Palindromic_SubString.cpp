#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0) return "";
        
        vector<string> arr;

        for (int i=0;i<len-1;i++){
        int start = i;
        int end = len - 1;
        while(start <= end){
            if(s[start] == s[end]){
                string subStr = s.substr(start, end - start + 1);
                string revSubStr = subStr;
        
                reverse(revSubStr.begin(), revSubStr.end());
    
                if(subStr.compare(revSubStr) == 0){
                    arr.push_back(subStr);
                }
            }
            end--;
        }
       }
        string longest;
        for(const auto& xyz: arr){
            if(xyz.length() > longest.length()){
                longest = xyz;
            }
       }
        return longest;
    }

};
