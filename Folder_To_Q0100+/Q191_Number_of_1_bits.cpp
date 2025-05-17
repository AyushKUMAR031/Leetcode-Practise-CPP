
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n > 0){
            count += (n & 1); //checking the lsb with 1 to get the whether it is 1 or not 
            n = n >> 1; //then right shifting it
        }
        return count;
    }
};
