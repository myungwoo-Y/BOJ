// 1293. Shortest Path in a Grid with Obstacles Elimination
struct Pos {
    int r, c, wall;
};

class Solution {
public:
    int rows, cols;
    vector<vector<int>> dirs = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };

    int getMinPath(int r, int c, int k, vector<vector<int>>& grid) {
        queue<Pos> q;
        vector<vector<vector<bool>>> visited(rows, vector<vector<bool>>(cols, vector<bool>(k+1)));
        int dist = 0;

        q.push({r, c, grid[r][c] == 1});

        while(!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [curR, curC, wall] = q.front();
                q.pop();

                if (curR == rows-1 && curC == cols-1) return dist;

                for (auto& dir : dirs) {
                    int nextR = curR + dir[0];
                    int nextC = curC + dir[1];

                    if (nextR < 0 || nextR >= rows || nextC < 0 || nextC >= cols) 
                        continue;

                    int nextWall = wall + grid[nextR][nextC];

                    if (visited[nextR][nextC][nextWall] || nextWall > k) continue;

                    visited[nextR][nextC][nextWall] = true;

                    q.push({nextR, nextC, nextWall});
                }
            }
            dist++;
        }

        return INT_MAX;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        // 0 : empty
        // 1 : obstacle
        rows = grid.size();
        cols = grid[0].size();
        int ret = INT_MAX;

        ret = min(ret, getMinPath(0, 0, k, grid));
        if (ret == INT_MAX)
            return -1;
        else 
            return ret;
    }
};