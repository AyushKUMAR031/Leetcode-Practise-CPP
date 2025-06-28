class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numIndex;
        for (int i = 0; i < nums.size(); ++i) {
            numIndex.push_back({nums[i], i});
        }

        sort(numIndex.begin(), numIndex.end(), greater<pair<int, int>>()); //sorting in descending

        vector<int> indices;
        for (int i = 0; i < k; i++) {
            indices.push_back(numIndex[i].second);
        }

        sort(indices.begin(), indices.end());

        vector<int> ans;
        for (int idx : indices) {
            ans.push_back(nums[idx]);
        }

        return ans;
    }
};
