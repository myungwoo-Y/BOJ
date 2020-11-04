#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>

#define LL long long int
#define loop(n) for(int I = 0; I < n; ++I)
#define sz(x) (int)x.size()
#define ALPHA 26
#define pii pair<int,int>
const int MAX = 987654321;
const int MIN = -987654321;
const char endL = '\n';

using namespace std;

bool indexCheck(int r, int c, int rowSize, int colSize) {
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}
struct D{
    int r, c, cnt;
};

D curPos;
int n, ans;
int sharkSize = 2, eatCount = 0;
int table[20][20];


vector<vector<int>> dirs = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
};

void updateCurPos(D newCurPos){
    curPos = newCurPos;
}

bool bfs(){
    queue<D> q;
    vector<vector<bool>> visited(n, vector<bool>(n));
    D prevCurPos = curPos;

    q.push(curPos);
    visited[curPos.r][curPos.c] = true;

    bool isFind = false;


    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        int tableValue = table[cur.r][cur.c];

        if(tableValue > 0 && tableValue < sharkSize){
            if(!isFind || cur.cnt < curPos.cnt){
                updateCurPos(cur);
            }else if(cur.cnt == curPos.cnt){
                if(cur.r < curPos.r){
                    updateCurPos(cur);
                }else if(cur.r == curPos.r && cur.c < curPos.c){
                    updateCurPos(cur);
                }
            }
            isFind = true;
        }



        for(auto dir: dirs){
            int newR = cur.r + dir[0];
            int newC = cur.c + dir[1];
            if(indexCheck(newR, newC, n, n)
               && !visited[newR][newC]
               && table[newR][newC] <= sharkSize){
                q.push({newR, newC, cur.cnt+1});
                visited[newR][newC] = true;
            }
        }
    }

    // 점 이동했는지 확인
    if(curPos.r != prevCurPos.r || curPos.c != prevCurPos.c){
        ans += curPos.cnt - prevCurPos.cnt;
        table[curPos.r][curPos.c] = 0;
        eatCount++;

        if(eatCount >= sharkSize){
            sharkSize++;
            eatCount = 0;
        }
        return true;
    }else{
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> table[i][j];
            if(table[i][j] == 9){
                curPos = {i, j, 0};
                table[i][j] = 0;
            }
        }
    }

    while(bfs());


    cout << ans;


    return 0;
}



