class Solution {
public:
    void solve(int i,int n,vector<int> &arr){
        arr.push_back(i);
        for(int j=0;j<=9;j++){
            int a = i*10+j;
            if(a> n){
                return;
            }
            solve(a,n,arr);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> arr;
        for(int i=1;i<=9;i++){
            if(i > n) break;
            solve(i,n,arr);
        }
        return arr;
    }
};

//fuccckkkk
