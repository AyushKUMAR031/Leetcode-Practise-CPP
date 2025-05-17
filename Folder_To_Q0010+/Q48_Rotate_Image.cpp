class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size(); // as n*n
        for (int i = 0; i < size; i++) { //Transpose the matrix: convert rows to columns.
            for (int j = i + 1; j < size; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < size; i++) { // Reverse each row.
            for (int j = 0; j < (size)/2; j++) {
                swap(matrix[i][j], matrix[i][size - j - 1]);
            }
        }
    }
};
