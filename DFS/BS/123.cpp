int sums[500][500][4];

vector<vector<int>> dirs = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

int find(pair<int, int> pos, vector<vector<int>>& matrix){
    
    int r = pos.first, c = pos.second;
    
    int ret = 1;
    
    for (int dir = 0; dir < 4; dir++) {
        if(sums[r][c][dir] == -1){
            int newR = r + dirs[dir][0];
            int newC = c + dirs[dir][1];
            
            if(newR < 0 || newR >= matrix.size() || newC < 0 || newC >= matrix[0].size() || matrix[r][c] >= matrix[newR][newC]) continue;
            
            sums[r][c][dir] = find({newR, newC}, matrix) + 1;
            
        }
        
        ret = max(ret, sums[r][c][dir]);
    }
    
    return ret;
}


int solve(vector<vector<int>>& matrix) {
    // Default value is -1
    memset(sums, -1, sizeof(sums));
    
    int ret = 0;
    
    for(int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++) {
            int curSum = find({i, j}, matrix);
            ret = max(ret, curSum);
        }
    }
    
    return ret;
}