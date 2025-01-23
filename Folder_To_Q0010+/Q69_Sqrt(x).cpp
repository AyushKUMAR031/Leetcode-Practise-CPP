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


//better writting
class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        if(x==0) return 0;
        int s = 1,e = x;
        while(s <= e){
            long long m = s + (e-s)/2;
            if(m*m == x){
                return m;
            }else if(m*m > x){
                e = m - 1;
            }else{
                //if x is not perfect sqr.
                // long long check = m+1;
                // if(check*check > x){
                //     return m;
                // }
                s = m + 1;
            }
        }
        return ans; // we can send directly e for not perfect sqr.
    }
};
