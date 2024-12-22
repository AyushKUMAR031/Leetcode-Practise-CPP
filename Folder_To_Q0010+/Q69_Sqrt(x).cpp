class Solution {
public:
    int mySqrt(int x) {
        int ans;
        if(x==0)
            return 0;
        int start = 1;
        int end = x;
        int mid;
        while(start<=end){
            mid=start + (end-start)/2;
            long long midSquare = (long long)mid * mid;
            if(midSquare>x){
                end=mid-1;
            }else if(midSquare<x){
                int check = mid+1;
                long long checkSquare = (long long)check * check;
                if(checkSquare>x){
                    ans = mid;
                    break;
                }
                start=mid+1;
            }else if(midSquare==x){
                ans = mid;
                break;
            }
        }
        return ans;
    }
};
