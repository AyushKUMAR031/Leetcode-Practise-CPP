//o(n log n)
class Solution {
public:
    int bits(int n){
        int count = 0;
        while(n > 0){
            count += (n & 1);
            n = n >> 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> a(n+1);

        for(int i=0;i<a.size();i++){
            a[i] = bits(i);
        }
        return a;
    }
};

// BEST 100% BEATS o(n)
```cpp
// Dynamic Programming with Bit Manipulation
// time: O(n)
// space: O(n)
class Solution {
public:
    vector<int> countBits(int n) {

        // vector of size n+1 with 0 as default value
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i >> 1] + (i & 1);
            // ans[i >> 1]: returns number of 1 bits in the part excluding the last bit (LSB)
            // bit i & 1: returns 1 if last bit is 1
        }

        return ans;
    }
};

/*
Example for i = 5 (0b101): (right shift makes the i to floor(i/2))
i >> 1 = 2 (0b10), ans[2] = 1, we have previously calculated for 0b10
i & 1 = 1 (since LSB is 1)
ans[5] = ans[2] + 1 = 1 + 1 = 2

so we can say that
for bits in i the formula is bits in (i/2) + lsb
*/
```
