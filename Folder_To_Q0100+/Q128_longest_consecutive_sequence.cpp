class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int lcs = 1, cs = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                // skip duplicates
                continue;
            } else if(nums[i] == nums[i-1] + 1) {
                cs++;
            } else {
                lcs = max(lcs, cs);
                cs = 1;
            }
        }

        lcs = max(lcs, cs);
        return lcs;
    }
};
