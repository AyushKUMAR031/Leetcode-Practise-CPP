class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end()); //sorting for implementation of 2 pointer

        int n = nums.size();

        for(int i=0;i<n-3;i++){ //two loop for fixing a,b

            if( i>0 && nums[i] == nums[i-1]) continue; //skipping duplicates

            for(int j=i+1;j<n-2; ){

                //two pointer for c,d
                int l = j+1;
                int r = n-1;

                while(l<r){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];

                    if(sum == target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;

                        while( l<r && nums[l] == nums[l-1]) l++; //skipping duplicates

                    }else if(sum < target){
                        l++;
                    }else{
                        r--;
                    }
                }
                
                j++;
                while( j<n-1 && nums[j]==nums[j-1]) j++;
            }
        }

        return ans;
    }
};
