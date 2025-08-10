class Solution {
public:
    bool issafe(int r,int c,vector<vector<char>>& board){
        //row check
        for(int i=0;i<9;i++){
            if(i != r && board[i][c] == board[r][c]) return false;
        }

        //col check
        for(int j=0;j<9;j++){
            if(j != c && board[r][j] == board[r][c]) return false;
        }

        //home grid
        // for this we divide the main grid into 3 sections 0,1,2 both row and col wise.
        // doing r/3 and c/3 we get that in which section the home grid lies.
            //ex: r=5,c=4 , 5/3 = 1 and 4/3 = 1 so we are in the 1 section row and col wise
            //(middle home grid)
            //now with multiplying it with 3 we get the starting index of the home grid.
            //1*3 = 3 and 1*3 = 3 so home grid starts from (3,3) and now we just have to see
            //for +2 boxes in row and col upto (3+2,3+2) -> (5,5) done.

        int hr = (r/3)*3, hc = (c/3)*3;
        for(int i=hr;i<=hr+2;i++){
            for(int j=hc;j<=hc+2;j++){
                if(i != r && j != c && board[i][j]==board[r][c]){
                    return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    if(!issafe(i,j,board)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
