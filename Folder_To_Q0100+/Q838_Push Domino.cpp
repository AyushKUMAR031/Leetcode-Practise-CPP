class Solution {
public:
    string pushDominoes(string dominoes) {
        s = 'L' + s + 'R' //we are adding our own in-effective non still domino at the end.
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
                res += string(span,s[prev]); //adding a string of length span where all char are s[prev] -> either L or R
            }
            // LR
            else if(s[prev]=='L' && s[curr] == 'R'){
                res += string(span,'.');
            }
            // RL
            else{
                res += string(span/2,'R') + string(span %2 , '.') + string(span / 2 , 'L');
            }
            prev = curr;
        }
        return res;
    }
};
