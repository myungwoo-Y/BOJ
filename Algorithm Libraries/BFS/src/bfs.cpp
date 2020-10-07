//
// Created by auddn on 2020-09-08.
//

// simple bfs

bool indexCheck(int r, int c, int rowSize, int colSize) {
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}


struct D{
    int r, c;
};

vector<vector<int>> dirs = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
};


void bfs(int i, int j, int condition){
    queue<D> q;
    q.push({i, j});
    visited[i][j] = true;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto dir: dirs){
            int newR = cur.r + dir[0];
            int newC = cur.c + dir[1];
            if(indexCheck(newR, newC, n, n)
               && !visited[newR][newC]
               && table[newR][newC] >= condition){
                q.push({newR, newC});
                visited[newR][newC] = true;
            }
        }
    }
}