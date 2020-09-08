#include <bits/stdc++.h>

#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
bool indexCheck(int r, int c, int rowSize, int colSize){
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}

using namespace std;

const char endL {'\n'};

const int rowSize = 3, colSize = 3;
unordered_map<int, int> m;
int cnt;
const int Target = 987654321;
vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
};

int getTableKey(vector<vector<int>> table){
    int ret = 0;
    int mul = 1;
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            ret += table[i][j]*mul;
            mul *= 10;
        }
    }
    return ret;
}




void search(vector<vector<int>> table){

    queue<int> q;
    int key = getTableKey(table);
    q.push(key);

    while(!q.empty()){
        int curKey = q.front();
        q.pop();

        if(curKey == Target)
            break;

        string s = to_string(curKey);
        int ninePos = s.find("9");
        int curR = ninePos/3;
        int curC = ninePos%3;
        for (int dir = 0; dir < 4; ++dir) {
            int newR = curR + directions[dir][0];
            int newC = curC + directions[dir][1];
            if(indexCheck(newR, newC, rowSize, colSize)){
                string newKeyStr = s;
                swap(newKeyStr[newR*3+newC], newKeyStr[curR*3+curC]);
                int newKey = stoi(newKeyStr);
                if(!m.count(newKey)){
                    m[newKey] = m[curKey]+1;
                    q.push(newKey);
                }
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
    vector<vector<int>> table(rowSize, vector<int>(colSize));
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            cin >> table[i][j];
            if(table[i][j] == 0){
                table[i][j] = 9;
            }
        }
    }
    int key = getTableKey(table);
    if(key == Target){
        cout << 0;
        return 0;
    }
    search(table);
    int ans = m[Target];
    if(ans > 0){
        cout << ans;
    }else{
        cout << -1;
    }
    return 0;
}