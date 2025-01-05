// basic recursion 
class Solution {
public:
    void backtrack(string digits, unordered_map<char,string> &keypad,vector<string> &answer,int depth,string current){
        //base case
        if(depth == digits.size()){
            answer.push_back(current);
            return;
        }

        //recursive case
        char digit = digits[depth];
        string letters = keypad.at(digit);

        for(char i : letters){
            backtrack(digits,keypad,answer,depth+1,current+i);
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        unordered_map<char,string> keypad= {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        if(digits.empty())
            return answer;
        backtrack(digits,keypad,answer,0,"");
        return answer;
    }
};

//best solution
class Solution {
public:
    void solve(string mapping[],string digits,vector<string>& ans,int i,string curr){
        if(i >= digits.size()){
            ans.push_back(curr);
            return;
        }

        int digit = digits[i] - '0';
        for(char ch : mapping[digit]){
            solve(mapping,digits,ans,i+1,curr+ch);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.empty())
            return ans;
        solve(mapping,digits,ans,0,"");
        return ans;
    }
};
