class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> prefix;
        int left,right,val = 0;
        int xor_ops = 0;
        for(auto i : arr){
            xor_ops = i^xor_ops;
            prefix.push_back(xor_ops);
        }

        for(auto i : queries){
            left = i[0];
            right = i[1];
            if(left == 0){
                val = prefix[right];
            }else{
                val = prefix[right] ^ prefix[left-1];
            }
            ans.push_back(val);
        }
        return ans;
    }
};

