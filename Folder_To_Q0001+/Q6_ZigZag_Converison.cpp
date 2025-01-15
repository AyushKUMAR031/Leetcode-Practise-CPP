//video sol -> https://youtu.be/Q2Tw6gcVEwc?si=D_ExZdj6Ix6t6GAo

class Solution {
public:
    string convert(string s, int n) {
        // The Concept is to get the algo for jumping to the desired char
        // So basically we get Count of Rows. ->

        // for 1st Row and last Row
        // so [ numRows - 1 ] to go down and same for coming up in the zig zag
        // pattern
        //  P [3-1 = 2 {A,Y} + {P,A} -> A]

        // for middle Row
        // each time we go down jump is reduced by 2. [4-1]*2 - 2.

        // if row is 1 string is same as given one.

        if(n == 1) return s;

        string res = "";

        for(int i=0;i<n;i++){
            int inc = (n-1)*2;
            for(int j=i;j<s.length(); j+=inc ){ //skipping by increment in general
                res += s[j];
                //working for the left over element in the mid rows i!=0 and i!=n-1 rows.
                if(i>0 && i<n-1 && (j+inc-2*i) < s.length()){
                    res += s[j+inc-2*i];
                }
            }
        }
        return res;
    }
};
