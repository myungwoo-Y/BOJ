//
// Created by auddn on 2020-09-07.
//

vector<vector<int>> dirs = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
};

// table dfs code
void dfs(int r, int c){
    if(visited[r][c])
        return;
    visited[r][c] = true;
    for(auto dir : dirs){
        int newR = r + dir[0];
        int newC = c + dir[1];
        if(!visited[r][c] && table[newR][newC] == condition){
            dfs(newR, newC);
        }
    }
}



// graph dfs code
bool indexCheck(int r, int c, int rowSize, int colSize) {
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}

void dfs(int v){
    if(visited[v])
        return;
    visited[v] = true;
    for (int i = 1; i <= vertexN; ++i) {
        if (!visited[i] && graph[v][i]) {
            dfs(i);
        }
    }
}


