class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num = 0;
        for(int i=0;i<32;i++){
            num = num << 1; //Push all bits in num one place left to make space for the new bit
            if(n & 1) num = num | 1; //check for last bit (if 1 set it with or operation)
            n = n >> 1; //reduce n; which right shift
        }
        return num;
    }
};
