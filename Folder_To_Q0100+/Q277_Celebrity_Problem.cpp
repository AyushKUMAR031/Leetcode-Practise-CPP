#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int getcelebrity(vector<vector<int>> &arr){
	int n = arr.size();
	stack<int> st;
	
	for(int i=0;i<n;i++){
		st.push(i);
	}
	
	while(st.size() > 1){
			int i = st.top();
			st.pop();
			int j = st.top();
			st.pop();
			
			if(arr[i][j] == 1){
				st.push(j);
			}else{
				st.push(i);
			}
	}
	
	int celeb = st.top();
	
	for(int i=0;i<n;i++){
		if(i!=celeb && (arr[celeb][i] == 1 || arr[i][celeb] == 0)){
			return -1;
		}
	}
	return celeb;
}

int main(){
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
	int ans = getcelebrity(arr);
	cout << "Celebrity is : " << ans << endl;
	
	return 0;
}
