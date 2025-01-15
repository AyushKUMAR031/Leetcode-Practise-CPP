class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        prefix.resize(r+1,vector<int>(c+1,0));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                prefix[i+1][j+1] = matrix[i][j] + (i > 0 ? prefix[i][j+1] : 0) + (j>0 ? prefix[i+1][j] : 0) 
                - ((i>0 && j>0)? prefix[i][j] : 0);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2+1][col2+1]-prefix[row1][col2+1]-prefix[row2+1][col1]+prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
