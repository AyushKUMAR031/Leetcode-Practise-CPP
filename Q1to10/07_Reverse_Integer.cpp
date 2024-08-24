/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int output = 0;
        while(x != 0){
            int digit = x%10;
            if(output >INT_MAX/10 || output<INT_MIN/10){
                return 0;
            }
            output = output*10 + digit;
            x/=10;
        }
        return output;
    }
};
// @lc code=end

