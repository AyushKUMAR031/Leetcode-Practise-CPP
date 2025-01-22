//using Binary Search

//ok ok logic
class Solution {
public:
    void bSearch(vector<int>& nums, int s,int e,int target,vector<int>& occ){
        int mid = s + (e-s)/2;
        while(s<=e){
            if( nums[mid] < target){
                s = mid + 1;
            }
            if( nums[mid] > target){
                e = mid - 1;
            }
            if( nums[mid] == target){
                occ.push_back(mid);
                bSearch(nums,0,mid-1,target,occ);
                bSearch(nums,mid+1,nums.size()-1,target,occ);
                return;
            }
            mid = s + (e-s)/2;
        }
        return;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> occ;

        bSearch(nums,0,nums.size()-1,target,occ);
        if(occ.size() == 0){
            return {-1,-1};
        }else if(occ.size() == 1){
            return {occ[0],occ[0]};
        }
        sort(occ.begin(),occ.end());
        return {occ[0],occ[occ.size()-1]};
        
    }
};

//god logic

