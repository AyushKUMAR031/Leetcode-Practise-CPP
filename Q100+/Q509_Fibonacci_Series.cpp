class Solution {
public:
    int fib(int n) {
        if(n < 1)
            return 0;
        if( n == 1)
            return 1;
        int a = 0,b = 1,sum = 0;
        for(int i=2;i<=n;i++){
            sum = a+b;
            a = b;
            b = sum;
        }
        return sum;      
    }

};

//by dp recursive and memoization
class Solution {
public:
    int fibo(int n,vector<int> &dp){
        //step 1
        if(n <= 1)
            return n;

        //step 2
        if(dp[n] != -1){
            return dp[n];
        }

        //step 3
        dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        int a = fibo(n, dp);
        return a;
    }
};


