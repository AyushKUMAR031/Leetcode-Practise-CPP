class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                myStack.push(ch);
            }
            else {
                if (myStack.empty() || 
                    (ch == ')' && myStack.top() != '(') ||
                    (ch == '}' && myStack.top() != '{') ||
                    (ch == ']' && myStack.top() != '[')) {
                    return false;
                }
                myStack.pop();
            }
        }

        if(myStack.empty()){
            return true;
        }
        return false;
    }
};
