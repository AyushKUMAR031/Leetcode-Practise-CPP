class Solution {
public:
    int M = 1e9 + 7;
    long long power(int base,long long p){
        if( p == 0 ) return 1;
        long long res = power(base,p/2) % M;
        if(p % 2 == 0){
            res = (res*res) % M;
        }
        else {
            res = (res*res*base) %M;
        }
        return res;
    }

    
    int countGoodNumbers(long long n) {
        long long evenPlace = (n + 1)/2;
        long long oddPlace = n/2;
        long long res = (power(5,evenPlace) * power(4,oddPlace)) % M ;
        return (int) res;
    }
};
