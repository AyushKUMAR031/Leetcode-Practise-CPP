//My method 134ms
class NumArray {
public:
    vector<int> a;
    NumArray(vector<int>& nums) {
        a = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i= left; i<= right; i++){
            sum+= a[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */





//pro Method 22ms
class NumArray {
public:
    vector<int> prefixSum_Array;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i= 0; i< nums.size(); i++){
            sum += nums[i];
            prefixSum_Array.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {     
        if(left == 0){
            return prefixSum_Array[right];
        }       
        return prefixSum_Array[right]-prefixSum_Array[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
