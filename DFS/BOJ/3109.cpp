#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>

#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#define sz(x) (int)x.size()

const int MAX = 987654321;
const int MIN = -987654321;

const char endL = '\n';

using namespace std;

int rowN, colN;

vector<vector<int>> table;


bool indexCheck(int r, int c, int rowSize, int colSize) {
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}

vector<vector<int>> dirs = {
        {0, 1},
        {-1, 1},
        {1, 1}
};

bool dfs(int r, int c){
    if(c == colN-1){
        return true;
    }

    if(table[r][c])
        return false;

    table[r][c] = 1;

    vector<int> dirOrders = {1, 0, 2};


    for(auto idx : dirOrders) {
        auto dir = dirs[idx];
        auto[newR, newC] = make_pair(r + dir[0], c + dir[1]);
        if(indexCheck(newR, newC, rowN, colN)
           && !table[newR][newC]){
            if(dfs(newR, newC)){
                table[newR][newC] = 1;
                return true;
            }
        }
    }
    return false;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    cin >> rowN >> colN;

    table.resize(rowN);

    for (int i = 0; i < rowN; ++i) {
        for (int j = 0; j < colN; ++j) {
            char ch {};
            cin >> ch;
            table[i].push_back(ch == 'x');
        }
    }

    int ans = 0;
    for (int r = 0; r < rowN; ++r) {
            ans += dfs(r, 0);
    }

    cout << ans;

    return 0;
}



