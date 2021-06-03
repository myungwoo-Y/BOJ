#include <bits/stdc++.h>
#include <stdio.h>

#define SI string::iterator
#define LL long long int
#define loop(n) for(int xssss = 0; x < n; ++x)

#include <ctype.h>
const int MAX = 987654321;
const int MIN = -987654321;

bool indexCheck(int r, int c, int rowSize, int colSize) {
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}

const char endL = '\n';

using namespace std;
vector<vector<int>> graph;
vector<int> dp;
vector<int> isEarlyList;

int N;

void dfs(int v, int parent)
{
    int childSum = 0;
    int childCount = 0;
    bool isEarly = false;

    for (int child : graph[v]) {

        if (child == parent)
            continue;
        childCount++;
        dfs(child, v);
        isEarly |= !isEarlyList[child];
        childSum += dp[child];
    }

    isEarlyList[v] = isEarly;

    dp[v] += childSum + isEarly;
}

void sumEarlyAdapter()
{
    dfs(1, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    cin >> N;

    graph.resize(N+1);
    dp.resize(N+1);
    isEarlyList.resize(N+1);

    for (int i = 0; i < N-1; ++i) {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    sumEarlyAdapter();
    cout << dp[1];
    return 0;
}


