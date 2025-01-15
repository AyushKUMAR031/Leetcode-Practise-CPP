class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxwater = 0;
        while(l<r){
            int minHeight = min(height[l],height[r]);
            int water = minHeight*(r-l);
            if(maxwater < water) maxwater = water;
            if(height[r] > height[l]){ 
                l++;
            }else{ 
                r--; 
            }
        }
        return maxwater;
    }
};

// video solution -> https://youtu.be/w7ftYsZtIbs?si=8dekLkEZdnuVWyCC
