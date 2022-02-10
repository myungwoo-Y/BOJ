// 827. Making A Large Island
class Solution {
public:
    int R, C, maxArea;
    
    vector<vector<int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    
    unordered_map<int, int> areaMap;
    
    int getArea(int r, int c, int flag, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        
        int ret = 1;
        
        q.push({r, c});
        grid[r][c] = flag;
        
        while(!q.empty()) {
            auto [curR, curC] = q.front();
            q.pop();
            
            for (int dir = 0; dir < 4; dir++) {
                int newR = curR + dirs[dir][0];
                int newC = curC + dirs[dir][1];
                
                if (newR < 0 || newR >= R || newC < 0 || newC >= C) continue;
                
                if (grid[newR][newC] == 1) {
                    grid[newR][newC] = flag;
                    q.push({newR, newC});
                    ret++;
                }
            }
        }
        
        return ret;
    }
    
    void markEachArea(vector<vector<int>>& grid) {
        int flag = 2;
        int ret = 0;
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 1) {
                    int area = getArea(i, j, flag, grid);;
                    areaMap[flag] = area;
                    maxArea = max(maxArea, area);
                    flag++;
                }
            }
        }
    }
    
    int sumNearIsland(int r, int c, vector<vector<int>>& grid) {
        unordered_set<int> s;
        
        for (int dir = 0; dir < 4; dir++) {
            int newR = dirs[dir][0] + r;
            int newC = dirs[dir][1] + c;
            
            if ((newR < 0 || newR >= R || newC < 0 || newC >= C) || grid[newR][newC] == 0) {
                continue;
            } else {
                s.insert(grid[newR][newC]);
            }
        }
        
        int sum = 1;
        
        for (int flag : s) {
            sum += areaMap[flag];
        }
        
        return sum;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        
        int ret = 0;
        
        markEachArea(grid);
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (!grid[i][j]) {
                    grid[i][j] = 1;
                    ret = max(ret, sumNearIsland(i, j, grid));
                    grid[i][j] = 0;
                }
            }
        }
        
        if (ret == 0) {
            return maxArea;
        } else {
            return ret;
        }
    }
};