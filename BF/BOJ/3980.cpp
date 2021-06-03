#include <bits/stdc++.h>

#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
const int MAX = 987654321;
const int MIN = -987654321;
bool indexCheck(int r, int c, int rowSize, int colSize){
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}

using namespace std;
const char endL = '\n';
const int playerSize = 11;

int ans = MIN;

struct D{
    int value {-1}, idx {-1};
};

vector<vector<D>> scores;

bool checkAllAsign(vector<bool>& visited){
    for (int i = 0; i < visited.size(); ++i) {
        if(!visited[i])
            return false;
    }
    return true;
}

void search(int cur, int sum, vector<bool>& visited){
    if(cur >= playerSize){
        if(checkAllAsign(visited))
            ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < scores[cur].size(); ++i) {
        D d = scores[cur][i];
        if(!visited[d.idx]){
            visited[d.idx] = true;
            search(cur+1, sum+d.value, visited);
            visited[d.idx] = false;
        }
    }
    search(cur+1, sum, visited);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int testCase {};
    cin >> testCase;

    loop(testCase){
        scores = vector<vector<D>>(playerSize, (vector<D>()));
        ans = MIN;
        for(int i = 0; i < playerSize; i++){
            for (int j = 0; j < playerSize; ++j) {
                int value {};
                cin >> value;
                if(value > 0)
                    scores[i].push_back({value, j});
            }
        }
        vector<bool> visited(playerSize);
        search(0, 0, visited);
        cout << ans << endL;
    }

    return 0;
}