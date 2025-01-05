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
