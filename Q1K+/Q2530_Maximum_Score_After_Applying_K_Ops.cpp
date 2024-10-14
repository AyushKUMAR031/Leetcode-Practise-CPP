class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        long long int max_score = 0;
        priority_queue<int> pq;

        for(int num : nums){
            pq.push(num);
        }

        for(int i=0;i<k;i++){
            max_score += pq.top();
            int replace = ceil(pq.top() / 3.0);
            pq.pop();
            pq.push(replace);
        }
        return max_score;
    }
};
