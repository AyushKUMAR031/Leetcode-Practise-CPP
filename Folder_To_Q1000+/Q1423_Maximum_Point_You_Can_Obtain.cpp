class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += cardPoints[i];
        }
        int maxsum = sum;
        int i = k-1;
        while(i >= 0){
            //removing last added value from left side.
            sum -= cardPoints[i];
            //and adding value from right side.
            sum += cardPoints[n-k+i];
            i++;

            maxsum = max(maxsum,sum);
            k--;
        }
        return maxsum;
    }
};
