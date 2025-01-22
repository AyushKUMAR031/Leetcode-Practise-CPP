//god approach in BS
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0, e = arr.size() - 1, m = s + ( e - s)/2;
        while(s<=e){
            if(m-1>=0 && arr[m-1] > arr[m]){
                e = m - 1;
            }else if(m+1<=arr.size()-1 && arr[m+1] > arr[m]){
                s = m + 1;
            }else{
                return m;
            }
            m = s + ( e - s )/2;
        }
        return 0;
    }
};
