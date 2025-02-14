class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        //we need to use the modulo thing to check in circular loop
        //doubling the iteration of array - concept of circular array

        for(int i=2*n-1; i>=0 ; i--){
            // used to pop smaller elements
          while(!st.empty() && nums[st.top()] <= nums[i%n]){
            st.pop();
          }

          //values added for i>=n then reassure with i<n considering loop.
          ans[i%n] = st.empty() ? -1 : nums[st.top()]; 

          st.push(i%n); //valid index
        }
        return ans;
    }
};
