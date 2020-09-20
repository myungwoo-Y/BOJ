//
// Created by auddn on 2020-09-08.
//

// simple bfs

bool indexCheck(int r, int c, int rowSize, int colSize) {
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}


struct Pos{
    int r, c;
};

vector<vector<int>> dirs = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
};


void bfs(int i, int j, int condition){
    queue<Pos> q;
    q.push({i, j});
    visited[i][j] = true;

    while(!q.empty()){
        Pos pos = q.front();
        q.pop();
        for(auto dir: dirs){
            auto [newR, newC] = make_pair(pos.r + dir[0], pos.c + dir[1]);
            if(indexCheck(newR, newC, n, n)
               && !visited[newR][newC]
               && table[newR][newC] >= condition){
                q.push({newR, newC});
                visited[newR][newC] = true;
            }
        }
    }
}