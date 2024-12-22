//best approach and logic by me ayush kumar aka itachi uchiha
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> arr;
        string nums = to_string(num);
        bool isSwap = false;

        //greedy
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<nums.length();i++){
            int digit = nums[i] -'0';
            arr.push_back(digit);
            pq.push({digit,i});
        }
        
        for (size_t i = 0; i < arr.size(); i++){
            if(pq.top().first > arr[i]){
                swap(arr[i], arr[pq.top().second]);
                isSwap = true;
                break;
            }else{
                if(i == pq.top().second){
                    pq.pop();
                }else{
                    int d = pq.top().first;
                    int p = pq.top().second;
                    pq.pop();
                    pq.pop();
                    pq.push({d,p});
                }
            }
        }

        if(isSwap){
            int result = 0;
            for (int digit : arr) {
                result = result * 10 + digit;
            }
            return result;
        }
        return num;
    }
};
