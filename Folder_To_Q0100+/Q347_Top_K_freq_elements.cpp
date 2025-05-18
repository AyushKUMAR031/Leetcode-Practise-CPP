//o(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int i : nums){
            mp[i]++;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n + 1); //bucket array
        /*
        Think of a "bucket" as a container that groups items by a specific property — in this case, frequency.
        */
        for(auto& [num, freq] : mp){
            bucket[freq].push_back(num);
        }

        for(int i = n; i >= 0 && ans.size() < k; i--){
            for(int val : bucket[i]){
                ans.push_back(val);
                if(ans.size() == k) break;
            }
        }

        return ans;
    }
};
