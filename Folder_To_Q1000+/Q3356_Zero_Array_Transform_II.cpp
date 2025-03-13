class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries,int mid){
        int n = nums.size();
        vector<int> temp(nums);
        vector<int> check(n+1,0);
        
        for(int i=0;i < mid;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            check[l] -= val; //making a diff array in O(1) for all queries till mid
            if(r+1 < n){
                check[r+1] += val;
            }
        }

        int currDecrement = 0;
        for(int i=0;i<n;i++){ //updating the temp values iteratively
            currDecrement += check[i];
            temp[i] += currDecrement;
            if(temp[i] > 0) return false; //if any value remains greater than zero ->false
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        //queries to sequence mei hi hoga
        //toh ek types queries apply karna sorted order hua
        //toh binary search toh banta hai na.
        int l = 0;
        int r = queries.size();
        int ans = -1;

        while(l <= r){
            int mid = (l+r)/2;
            if(isZeroArray(nums,queries,mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};
