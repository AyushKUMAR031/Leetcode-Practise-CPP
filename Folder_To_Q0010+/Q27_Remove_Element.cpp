class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> resultSet;
        for(auto &values : nums){
            if(values != val){
                resultSet.push_back(values);
            }
        }
        int k = resultSet.size();
        resultSet.swap(nums);
        return k;
    }
};
