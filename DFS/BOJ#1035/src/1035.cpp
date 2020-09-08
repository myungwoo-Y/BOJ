#include <bits/stdc++.h>
#include <stdio.h>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
const int MAX = 987654321;
const int MIN = -987654321;
bool indexCheck(int r, int c, int rowSize, int colSize){
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}
const char newline = '\n';

using namespace std;
int boardN = 5, ans = MAX;
bool isSelected[5][5];

struct Pos{
    int r, c;
};

vector<Pos> points;

vector<vector<int>> dirs = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
};

Pos curPos;

bool bfs(){
    vector<vector<bool>> visited;
    visited.resize(boardN, vector<bool>(boardN));

    queue<Pos> q;
    q.push(curPos);
    visited[curPos.r][curPos.c] = true;
    int cnt = 1;

    while(!q.empty()){
        Pos pos = q.front();
        q.pop();
        for(auto dir: dirs){
            auto [newR, newC] = make_pair(pos.r + dir[0], pos.c + dir[1]);
            if(indexCheck(newR, newC, boardN, boardN)
               && !visited[newR][newC]
               && isSelected[newR][newC]){
                q.push({newR, newC});
                visited[newR][newC] = true;
                cnt++;
            }
        }
    }
    return cnt == points.size();
}

int cal(Pos curPos, int order){
    Pos originPos = points[order];
    return abs(curPos.r - originPos.r) + abs(curPos.c - originPos.c);
}

void dfs(int order, int dist){
    if(dist >= ans)
        return;

    if(order >= points.size()){
        if(bfs())
            ans = min(ans, dist);
        return;
    }

    for (int i = 0; i < boardN; ++i) {
        for (int j = 0; j < boardN; ++j) {
            if(!isSelected[i][j]){
                isSelected[i][j] = true;
                curPos = {i, j};
                dfs(order + 1, dist + cal({i, j}, order));
                isSelected[i][j] = false;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    for (int i = 0; i < boardN; ++i) {
        for (int j = 0; j < boardN; ++j) {
            char inputChar;
            cin >> inputChar;
            if(inputChar == '*')
                points.push_back({i, j});
        }
    }

    dfs(0, 0);

    cout << ans;

    return 0;
}


