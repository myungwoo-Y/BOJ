#include <bits/stdc++.h>
#include <queue>
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
const char endL = '\n';
using namespace std;

vector<vector<int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
};
int dirSize = dirs.size();

vector<vector<char>> arr;

bool visited[10][10];
int colSize, rowSize, k;
int ans;

void dfs(int r, int c, int count){
    if(!indexCheck(r,c,rowSize,colSize) || count > k)
        return;

    if(arr[r][c] == 'T')
        return;

    if(r == 0 && c == colSize-1 && count == k){
        ans++;
        return;
    }

    for (int i = 0; i < dirSize; ++i) {
        auto dir = dirs[i];
        auto [newR, newC] = make_tuple(r+dir[0], c+dir[1]);
        if(!visited[newR][newC]){
            visited[newR][newC] = true;
            dfs(newR, newC, count+1);
            visited[newR][newC] = false;
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
    cin >> rowSize >> colSize >> k;

    arr.resize(rowSize, vector<char>(colSize));
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            cin >> arr[i][j];
        }
    }

    visited[rowSize-1][0] = true;
    dfs(rowSize-1, 0, 1);
    cout << ans;

    return 0;
}


