class Solution {
public:
    double power(double x,long long n){
        if(n == 0) return 1;
    
        double ans = power(x,n/2);
        if(n%2 == 0) return ans*ans;
        return x*ans*ans;
    }

    double myPow(double x, int n) {
        long long exp = n;
        if(exp < 0){
            x = 1/x;
            exp = -exp;
        }
        return power(x,exp);
    }
};
