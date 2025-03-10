//BEATS -100%
class Solution {
public:
    
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int maxLen = 1; //a single element is individually giving maxLen as 1
        int ans = 0;
        int n = colors.size(); 

        for(int i=1; i<=n+k-2; i++){ //iterating for a window of K size 
            // till the left(denoted as i) is at last value in the vector.
            if (colors[i%n]!= colors[(i-1+n)%n]){ // Check if the current color is different from the previous one //and using modulo for circular iteration(loop)
                maxLen++; 
            }else{ 
                maxLen = 1; //reset
            }
            if (maxLen >= k) //if we successfully increase the size of window till k ,i.e, we get an alternating group
                ans++; 
        }
        return ans;
    }
};
