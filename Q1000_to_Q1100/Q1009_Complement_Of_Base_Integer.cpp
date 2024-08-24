class Solution {
public:
    int bitwiseComplement(int n) {
        int m = n;
        // creating a bit series to exclude unwanted bits in result
        int mask = 0;

        //end case of 0 as input
        if(n==0){
            return 1;
        }
        
        while(m!=0){
            mask = (mask << 1);//shifting to left
            mask = mask | 1;//setting the last bit to 1
            m = m >> 1;
        }

        int result = (~n) & mask;

        return result;
    }
};
