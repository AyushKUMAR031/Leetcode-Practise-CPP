class Solution {
public:
    int minLength(string s) {
        stack <char> mystack; 
        //we can pop "AB" or "CD";
        for(char i : s){
            if(!mystack.empty() && (i == 'B' || i == 'D')){
                char j = mystack.top();
                if( (j == 'A' && i=='B') || (j=='C' && i=='D')){
                    mystack.pop();
                    continue;
                }
            }
            mystack.push(i);
        }
        return mystack.size();
    }
};
