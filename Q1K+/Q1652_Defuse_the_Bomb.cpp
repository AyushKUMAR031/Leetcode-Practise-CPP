class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> final(code.size(),0);
        int l = code.size();
        if (k == 0) return final;

        if(k>0){
            for(int i=0;i<l;i++){
                for(int j=1;j<=k;j++){
                    final[i] += code[(i+j)%l];
                } 
            }
        }else if(k < 0){
            int t = abs(k);
            for(int i=0;i<l;i++){
                for(int j=1;j<=t;j++){
                    final[i] += code[(i+l-j)%l];
                } 
            }
        }
        return final;
    }
};
