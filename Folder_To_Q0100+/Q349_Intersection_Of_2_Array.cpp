//good
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> check(nums1.begin(),nums1.end());
        unordered_set<int> ans;

        for(int i : nums2){
            if(check.find(i) != check.end()){
                ans.insert(i);
            }
        }

        return vector<int>(ans.begin(),ans.end());
    }
};

//best
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> check1(nums1.begin(),nums1.end());
        unordered_set<int> check2(nums2.begin(),nums2.end());
        vector<int> ans;

        for(int i : check2){
            if(check1.find(i) != check1.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
