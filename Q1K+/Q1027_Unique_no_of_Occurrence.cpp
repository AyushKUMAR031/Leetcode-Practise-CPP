//using unordered map and set
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> frequencies;
        for(int i=0;i<arr.size();i++){
            frequencies[arr[i]]++;
        }
        set<int>freq;
        for(int x : frequencies){
            freq.insert(x.second);
        }

        return(freq.size()==frequencies.size());
    }
};
