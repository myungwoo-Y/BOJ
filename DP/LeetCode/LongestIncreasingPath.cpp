// Title : 329. Longest Increasing Path in a Matrix
class Solution {
public:
    vector<vector<int>> paths;
    vector<vector<int>> directions;
    int emptyPath = -1;
    int fillPath(int r, int c, vector<vector<int>>& matrix){
        int& ret = paths[r][c];
        
        // init default path value
        if (ret != emptyPath) {
            return ret;
        } else {
            ret = 1;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int newR = r + directions[dir][0];
            int newC = c + directions[dir][1];
            
            if (newR < 0 || newR >= matrix.size() || newC < 0 || newC >= matrix[0].size()) continue;
            
            if (matrix[r][c] > matrix[newR][newC]) {
                int newCnt = fillPath(newR, newC, matrix) + 1;
                ret = max(ret, newCnt);
            }
        }
        
        return ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        paths = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), emptyPath));
        directions = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        
        for (int i = 0; i < paths.size(); i++) {
            for (int j = 0; j < paths[0].size(); j++) {
                if (paths[i][j] == emptyPath) {
                    fillPath(i, j, matrix);
                }
                ret = max(ret, paths[i][j]);
            }
        }
        
        return ret;
    }
};