//implementation of Kadane's Algo
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //its a subarray so its contiguous.
        if(nums.size() == 1) return nums[0];
        int product = 1;
        int maxProduct = INT_MIN;

        for(int i=0;i<nums.size();i++){
            product *= nums[i];
            maxProduct = max(maxProduct,product);
            if(product == 0) product = 1;
        }
        
        product = 1;

        for(int i=nums.size()-1;i>=0;i--){
            product *= nums[i];
            maxProduct = max(maxProduct,product);
            if(product == 0) product = 1;
        }

        return maxProduct;
    }
};

---
Approach
The Approach to this question is exactly same as Kadane's Algo the only differece is, we will be traversing the array from both sides i.e left to right ( lets say the max prod is maxi1 ) and from right to left ( say max prod is maxi2 ), now the final answer will we max of maxi1 and maxi2.

Ques : Why do we have a need to traverse from right to left ??
Ans : lets take an example
arr {-8,5,3,1,6}

// By traversing left to right we have an answer maxi1.
maxi1 = -720 , which is clearly not the max prod value.
-> The whole concept lies in this statement - As we can see that there is only 1 negative no. ( if we consider that no. then the final answer can never be positive ), therefore to avoid this situation we also traverse from right to left to get the final maximum prod.
