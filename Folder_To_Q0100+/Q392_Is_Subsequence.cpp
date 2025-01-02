//worst
class Solution {
public:
    bool solve(string s, string t, int index1,int index2){
        if(s.empty()) return true;
        if(t.empty()) return false;

        if(index2 >= t.length()) return false;

        if(s[index1] == t[index2]){
            if(index1 == s.length()-1) return true;
            return solve(s,t,index1+1,index2+1);
        }
        
        return solve(s,t,index1,index2+1);
    }
    bool isSubsequence(string s, string t) {
        return solve(s,t,0,0);
    }
};

//best
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j = 0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]) i++;
            j++;
        }
        if(i == s.size())
            return true;
        return false;
    }
};
