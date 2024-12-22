class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }else{
                if(s[i+1] == ')' && i+1<s.size()){
                    if(!st.empty()){
                        st.pop();
                    }else{
                        ans++;
                    }
                    i++;
                }else{
                    if(!st.empty()){
                        st.pop();
                        ans++;
                    }else{
                        ans += 2;
                    }
                }
            }
        }
        int extra = st.size()*2;
        ans += extra;

        return ans;
    }
};
