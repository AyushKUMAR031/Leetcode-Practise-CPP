class Solution {
public:
    void dfs(int Node,vector<vector<int>> &adj,vector<int> &visited){
        visited[Node] =true;

        for(auto i : adj[Node]){
            if(!visited[i]){
                dfs(i,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);
        vector<int> visited(V,0); //visited vector

        //create a proper adjList from the given matrix
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count =0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
        }

        return count;
    }
};
