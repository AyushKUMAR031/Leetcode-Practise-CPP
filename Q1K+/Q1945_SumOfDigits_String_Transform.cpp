class Solution {
public:
    int getLucky(string s, int k) {
        int sum =0;
        for(char letter : s){
            int val = letter -'a' + 1;
            cout<<val<<endl;
            while(val>0){
                sum+=val%10;
                val/=10;
            }

        }
        k--;
        for(int i=k;i>0;i--){
            int transform =0;
            while(sum>0){
                transform+=sum%10;
                sum/=10;
            }
            sum=transform;
        }
        return sum;
    }
};
