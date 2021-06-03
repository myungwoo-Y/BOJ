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
const int MaxPos = 75001;

const char endL = '\n';

using namespace std;

int rowN, colN, labelN = 1;
int labelCount = 0;
const int limitTableSize = 30;
int table[limitTableSize][limitTableSize];
bool visited[limitTableSize][limitTableSize];


vector<vector<int>> dirs = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
};

// table dfs code
void labelDFS(int r, int c){
    if(table[r][c] != MAX)
        return;
    table[r][c] = labelN;
    labelCount++;
    for(auto dir : dirs){
        int newR = r + dir[0];
        int newC = c + dir[1];
        if(table[newR][newC] == MAX){
            labelDFS(newR, newC);
        }
    }
}

vector<vector<pii>> makeCombination(){
    vector<pii> elements;
    int k = 2;

    for (int i = 1; i <= rowN; ++i) {
        for (int j = 1; j <= colN; ++j) {
            elements.push_back({i, j});
        }
    }

    vector<int> combination;

    for(int i=0; i<k; i++){
        combination.push_back(1);
    }

    for(int i=0; i < elements.size() - k; i++){
        combination.push_back(0);
    }

    vector<vector<pii>> ret;

    sort(combination.begin(), combination.end());
    do{
        vector<pii> temp;
        // 고른원소 사용
        for(int i=0; i < combination.size(); i++){
            if(combination[i] == 1){
                temp.push_back(elements[i]);
            }
        }

        ret.push_back(temp);

    }while(next_permutation(combination.begin(), combination.end()));

    return ret;
}

// -1로 둘러쌓여있는지 확인한다
bool isSurroundedDfs(int r, int c){
    if(visited[r][c])
        return true;

    if(table[r][c] == 0){
        return false;
    }

    bool ret = true;

    visited[r][c] = true;

    for(auto dir : dirs){
        int newR = r + dir[0];
        int newC = c + dir[1];
        if(!visited[newR][newC] && table[newR][newC] != -1){
            ret &= isSurroundedDfs(newR, newC);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif


    map<int, int> m;
    set<pii> s;
    cin >> rowN >> colN;

    memset(table, -1, sizeof(table));

    // 테이블값 전처리
    for (int i = 1; i <= rowN; ++i) {
        for (int j = 1; j <= colN; ++j) {
            int v {};
            cin >> v;
            if(v == 1){
                table[i][j] = -1;
            }else if(v == 2){
                table[i][j] = MAX;
            }else{
                table[i][j] = 0;
            }
        }
    }

    // 라벨링
    for (int i = 1; i <= rowN; ++i) {
        for (int j = 1; j <= colN; ++j) {
            if(table[i][j] == MAX){
                labelDFS(i, j);
                s.insert({i, j});

                m[labelN] = labelCount;
                labelCount = 0;

                labelN++;
            }
        }
    }

    vector<vector<pii>> pairsList = makeCombination();

    int ans = 0;

    // 모든 경우의 수 확인
    for(auto pairs : pairsList){
        auto a = pairs[0];
        auto b = pairs[1];

        // 두 좌표 모두 비어있는지 확인
        if(table[a.first][a.second] == 0
           && table[b.first][b.second] == 0){
            table[a.first][a.second] = -1;
            table[b.first][b.second] = -1;

            int tempAns = 0;

            for(auto it = s.begin(); it != s.end(); it++){
                memset(visited, 0, sizeof(visited));
                if(isSurroundedDfs(it->first, it->second)){
                    tempAns += m[table[it->first][it->second]];
                }
            }

            ans = max(ans, tempAns);

            table[a.first][a.second] = 0;
            table[b.first][b.second] = 0;
        }
    }

    cout << ans;

    return 0;
}



