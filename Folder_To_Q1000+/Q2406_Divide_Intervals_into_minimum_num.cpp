class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq; //minimum heap waala pq

        for(const auto interval : intervals){
            int start = interval[0];
            int end = interval[1];

            if(!pq.empty() && pq.top()<start){
                pq.pop(); // maximum check for min start of my intercal
            }
            pq.push(end); //earlier end
        }
        return pq.size();
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
