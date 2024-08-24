class Solution {
public:
  //method of checking all possible power of two
  //time complexity -> O(n)
  bool isPowerOfTwo(int n) {
      for(int i=0;i<=31;i++){
          if(n==pow(2,i)){
              return true;
              break;
          }
      }
      return false;
  }

  //method of bits
  //time complexity -> O(logn)

//bool isPowerOfTwo(int n) {
//    return  (n>0 && (n & (n-1))==0) ? true:false;
//  }


};
