class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,int val,int n){
        for(int i=0;i<n;i++){
            if(board[row][i] == (val + '0') || board[i][col] == (val + '0')) return false; //row and col check
            //3*3 matrix
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == (val + '0')) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int n = board[0].size();

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){

                //cell empty
                if(board[row][col] == '.'){
                    for(int val=1;val<=9;val++){
                        if(isSafe(board,row,col,val,n)){

                            board[row][col] = val + '0';

                            if(solve(board)){ 
                                return true;
                            }else{
                                //backtrack
                                board[row][col]= '.';
                            }       
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
