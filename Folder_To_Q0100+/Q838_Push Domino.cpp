class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = 'L' + dominoes + 'R'; //we are adding our own in-effective non still domino at the end.
        //to solve by taking two domino as reference over the iteration for LR,LL,RR,RL cases.

        string res;

        int prev = 0;
        for(int curr = 1; curr < s.size(); curr++){
            if(s[curr] == '.'){
                continue;
            }
            int between_domino = curr - prev - 1;

            //adding valid prev(which is from actual string dominos) to res
            if(prev > 0)
                res += s[prev];

            //cases
            //both LL or RR
            if(s[prev] == s[curr]){
                res += string(between_domino,s[prev]); //adding a string of length between_domino where all char are s[prev] -> either L or R
            }
            // LR
            else if(s[prev]=='L' && s[curr] == 'R'){
                res += string(between_domino,'.');
            }
            // RL
            else{
                res += string(between_domino/2,'R') + string(between_domino %2 , '.') + string(between_domino / 2 , 'L');
            }
            prev = curr;
        }
        return res;
    }
};
