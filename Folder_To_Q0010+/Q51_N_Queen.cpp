class Solution {
public:
    void addSolution(vector<vector<char>> board,vector<vector<string>>& ans,int n){
        vector<string> c;
        for(int i=0;i<n;i++){
            string temp  = ""; //storing the characters of a row to form a string
            for(int j=0;j<n;j++){
                temp+=board[i][j]; //concatenating char
            }
            c.push_back(temp); //storing the rows combination in a temporary vector c
        }
        ans.push_back(c);
    }

    bool isSafe(int row,int col,vector<vector<char>>& board,int n){
        //we are filling left to right ,so we will check for left side whether the queen is attacking or not.
        int x = row;
        int y = col;

        //checking for same row
        while(y>=0){
            if(board[x][y] == 'Q') return false;
            y--;
        }

        //checking for same col
        // since we are iterating by placing only one Queen in a row in the recursion, we are not needed to check
        // for column arrangement

        //checking for same diagonal
        //since we have filled the board L->R we will look for backward diagonals
        x = row;
        y = col;
        while(x>=0 && y>=0){
            if(board[x][y] == 'Q') return false;
            x--;
            y--;
        }
        x = row;
        y = col;
        while(x<n && y>=0){
            if(board[x][y] == 'Q') return false;
            x++;
            y--;
        }

        return true;

    }

    void solve(vector<vector<char>>& board,vector<vector<string>>& ans,int n,int col){
        //base
        if(col >= n){
            addSolution(board,ans,n);
            return;
        }

        //recursive
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){

                //if the square of the board is ok to place queen by checking is safe we add Q
                board[row][col] = 'Q';

                solve(board,ans,n,col+1); //recursive call

                //backtrack to remove the queen for another possible solution iteration.
                board[row][col] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.')); // created a board for keeping track of queen position
        vector<vector<string>> ans;

        solve(board,ans,n,0);

        return ans;
    }
};
