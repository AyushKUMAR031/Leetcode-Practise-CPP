class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        /*
        basically we are keeping track of whether whole row 0 and col 0 will become zero or not
            for that we use bool variables

            then after that the logic is to go inside (like to row 1 and col 1) and
            traverse whole matrix as usual.

            if at any point of time zero appears, we pin that row and col for zeros
            just by using the row 0 and col 0 as a rough paper 
                lets say 
                    we get 0 at matrix[5][9] then at whole row 5 and col 9 will become 0,
                    so we track it by changing the value at matrix[5][0] and matrix[0][9] to 0.

            later we will set all rows to 0 which are marked as 0 at matrix[row][0]
            and
            set all cols to 0 which are marked as 0 at matrix[0][col]

            then we will check whether the whole first row and first col were actually meant   to be zero or not by checking those bools.
        */
        bool firstrow = false, firstcol = false;

        //marking if row 0 or col 0 is having any 0 element or not.
        for(int i=0; i< row; i++){
            if(matrix[i][0] == 0){
                firstrow = true;
                break;
            }
        }

        for(int j=0; j< col; j++){
            if(matrix[0][j] == 0){
                firstcol = true;
                break;
            }
        }

        //checking from row 1 and col 1
        for(int i=1; i < row ; i++){
            for(int j = 1;j < col ; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }


        //checking our rough paper (row 0 and col 0) and changing whole line to 0
        for(int i=1; i < row; i++){
            for(int j = 1;j < col; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        //checking true identity of row 0 and col 0
        if(firstrow){
            for(int i=0; i<row; i++){
                matrix[i][0] = 0;
            }
        }
        if(firstcol){
            for(int j=0; j<col; j++){
                matrix[0][j] = 0;
            }
        }

    }
};
