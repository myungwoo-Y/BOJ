// Title : Sudoku Solver

class Solution {
public:
    char emptyBlock = '.';
    int limit = 9;
    
    bool checkRow(vector<vector<char>>& board, int r, int c){
        for(int i = 0; i < limit; i++){
            if(i == r) continue;
            
            if(board[i][c] == board[r][c])
                return false;
        }
        return true;
    }
    
    bool checkCol(vector<vector<char>>& board, int r, int c){
        for(int i = 0; i < limit; i++){
            if(i == c) continue;
            
            if(board[r][i] == board[r][c])
                return false;
            
        }
        return true;
    }
    
    bool checkGrid(vector<vector<char>>& board, int r, int c){
        int startR = r/3 * 3;
        int startC = c/3 * 3;
        
        for(int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++) {
                if(startR + i == r && startC + j == c) continue;
                
                if(board[startR + i][startC + j] == board[r][c])
                    return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int r, int c){
        
        // find solution
        if(r == limit && c == 0) return true;
        
        
        int nextR = (c+1)/limit + r;
        int nextC = (c+1)%limit;
        
        // find the correct ele in this char
        
        // if cur isn't empty
        if(board[r][c] != emptyBlock){
            return solve(board, nextR, nextC);
        }
        
        for (int el = 1; el <= limit; el++) {
            board[r][c] = el + '0';
            if(checkCol(board, r, c) && checkRow(board, r, c) && checkGrid(board, r, c) && solve(board, nextR, nextC))
                return true;
            board[r][c] = emptyBlock;
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};