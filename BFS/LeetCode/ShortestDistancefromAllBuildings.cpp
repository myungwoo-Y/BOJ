// 317. Shortest Distance from All Buildings

class Solution {
public:
    int rows = 0;
    int cols = 0;

    vector<vector<int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    void fillDistance(int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>>& sums) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        int cnt = 0, landCnt = 0;

        q.push({r, c});
        visited[r][c] = true;

        int step = 0;

        while(!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                auto [row, col] = q.front();
                q.pop();

                if (grid[row][col] == 0) {
                    sums[row][col][0] += step;
                    sums[row][col][1]++;
                }

                for (auto& dir : dirs) {
                    int newR = row + dir[0];
                    int newC = col + dir[1];

                    if (newR < 0 || newR >= rows || newC < 0 || newC >= cols
                        || visited[newR][newC]
                        || grid[newR][newC] != 0) 
                        continue;

                    q.push({newR, newC});

                    visited[newR][newC] = true;
                }
            } 
            step++;
        }
    }


    int shortestDistance(vector<vector<int>>& grid) {
        // 0 : land
        // 1 : building
        // 2 : obstacle
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<vector<int>>> sums(rows, vector<vector<int>>(cols, vector<int>(2)));

        int ret = INT_MAX;
        int numberOfBuilding = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    fillDistance(i, j, grid, sums);
                    numberOfBuilding++;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0 && sums[i][j][1] == numberOfBuilding) {
                    ret = min(ret, sums[i][j][0]);
                }
            }
        }

        if (ret == INT_MAX) {
            return -1;
        }
        
        return ret;
    }
};