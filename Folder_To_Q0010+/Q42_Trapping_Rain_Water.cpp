class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty() || height.size() < 3) return 0;

        int n = height.size();
        vector<int> leftMax(n, 0);  
        vector<int> rightMax(n, 0);

        leftMax[0] = height[0];
        for (int i=1;i<n;i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[n-1]=height[n-1];
        for (int i=n-2; i>=0;i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        int totalWater = 0;
        for (int i=0; i<n;i++) {
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }

        return totalWater;
    }
};

//[SolutionVideo](https://youtu.be/UZG3-vZlFM4?si=xhyOjPQI8V0-8sks)
