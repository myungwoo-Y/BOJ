// Largest Island After Land Cell Addition
vector<vector<int>> dirs = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

int bfs(int i, int j, int key, vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<vector<int>>& parent){
    queue<pair<int, int>> q;
    vector<pair<int, int>> posList;
    
    int areaSize = 1;
    
    posList.push_back({i, j});
    q.push({i, j});
    visited[i][j] = true;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(auto& dir : dirs){
            int newR = cur.first + dir[0];
            int newC = cur.second + dir[1];
            
            if(!(newR < 0 || newR >= matrix.size() || newC < 0 || newC >= matrix[0].size())
               && matrix[newR][newC] && !visited[newR][newC]){
                q.push({newR, newC});
                visited[newR][newC] = true;
                posList.push_back({newR, newC});
                areaSize += 1;
            }
        }
    }
    
    for(auto& pos : posList){
        matrix[pos.first][pos.second] = areaSize;
        parent[pos.first][pos.second] = key;
    }
    
    return areaSize;
}



int solve(vector<vector<int>>& matrix) {
    int ret = 0;
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
    vector<vector<int>> parent(matrix.size(), vector<int>(matrix[0].size(), 0));
    
    int key= 1;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] && !visited[i][j]){
                ret = max(ret, bfs(i, j, key, matrix, visited, parent));
                key++;
            }
        }
    }
    
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == 0){
                unordered_set<int> parentSet;
                int maxAreaSize = 1;
                for (auto& dir : dirs) {
                    int newR = i + dir[0];
                    int newC = j + dir[1];
                    
                    if(!(newR < 0 || newR >= matrix.size() || newC < 0 || newC >= matrix[0].size())){
                        int curParent = parent[newR][newC];
                        if(parentSet.find(curParent) == parentSet.end()){
                            maxAreaSize += matrix[newR][newC];
                            parentSet.insert(curParent);
                        }
                    }
                }
                ret = max(ret, maxAreaSize);
            }
        }
    }
    
    return ret;
}
