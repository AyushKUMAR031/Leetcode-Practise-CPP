class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //xor karke two unique values ka xor save karlenge
        int compute1 = 0;
        for(int i : nums){
            compute1 ^= i;
        }

        //ab kyuki dono unique hai that means koi ek bit toh diff hoga
        //ex : 3^5 -> 011 ^ 101 -> 110 yaha 2 bits diff hai
        //ab hum saare array ko split kardenge 0 and 1 for 2nd bit.

        int setbit = 1;//assuming set bit jo hai wo phela hi hai
        while((compute1 & setbit) == 0){
            setbit = setbit << 1; // rightmost set bit dhoondhna hai
            //setbit nahi mila toh right shift kardiya by 1 bit
        }//so r->l check mei to phele match kar jaye wo place pe setbit hai

        int count1 = 0,count0 = 0;

        for(int i : nums){
            if((i & setbit) == 0){
                count0 ^= i;
            }else{
                count1 ^= i;
            }
        }

        return {count0, count1};
    }
};
