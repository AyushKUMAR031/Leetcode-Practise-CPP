class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int index,int row,int col){
        //base case when the word is fully matched and the index is pointing to last char in word.
        if(index == word.size()) return true;

        //edge
        if(row < 0 || row > board.size()-1 || col < 0 || col > board[0].size()-1 || board[row][col] != word[index]){
            return false;
        }

        //tracking visited
        char temp = board[row][col];
        board[row][col] = '*';

        //recurion
        // Explore in all 4 directions
        int dirRow[] = {-1, 1, 0, 0}; // up, down
        int dirCol[] = {0, 0, -1, 1}; // left, right

        for(int d = 0; d < 4; ++d) {
            if(solve(board, word, index + 1, row + dirRow[d], col + dirCol[d])) {
                board[row][col] = temp; // backtrack before returning
                return true;
            }
        }

        //backtrack the curr pos
        board[row][col] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
};
