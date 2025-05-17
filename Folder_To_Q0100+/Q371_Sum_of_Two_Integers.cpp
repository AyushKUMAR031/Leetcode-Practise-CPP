class Solution {
public:
    int getSum(int a, int b) {
        // return a + b; we can directly do this but wanna try bit manipulation

        /*
        so in bits we calc a and b in 2 steps:
            one without carry -> a ^ b adds bits without carrying
            one with carry -> (a & b) << 1 {this first calc carry and then shift it to left    the next bit}

        this is done until all the carry is done,
            we check it by updating b value carry value, until b == 0.
        
        and then we return a (as we store answer in a)
        */

        while(b != 0){
            int carry = (a&b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
