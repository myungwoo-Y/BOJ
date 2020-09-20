//
// Created by auddn on 2020-09-07.
//

// simple dfs code

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


