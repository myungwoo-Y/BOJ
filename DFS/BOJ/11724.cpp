#include <bits/stdc++.h>

#define VII vector<vector<int>>
#define VDD vector<vector<double>>
#define VCC vector<vector<char>>
#define VSS vector<vector<string>>
#define VBB vector<vector<bool>>
#define VLL vector<vector<long long>>
#define VI vector<int>
#define VB vector<bool>
#define VS vector<string>
#define VC vector<char>
#define VD vector<double>
#define VL vector<long long>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>

using namespace std;

const string endL {"\n"};

int vertexN, m;
vector<vector<bool>> graph;
vector<bool> visited;
int ans;

void dfs(int v){
    if(visited[v])
        return;
    visited[v] = true;
    for (int i = 1; i <= vertexN; ++i) {
        if(!visited[i] && graph[v][i]){
            dfs(i);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    cin >> vertexN >> m;
    graph.resize(vertexN+1, vector<bool>(vertexN+1, false));
    visited.resize(vertexN+1, false);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    for (int i = 1; i <= vertexN; ++i) {
        if(!visited[i]){
            ans++;
            dfs(i);
        }
    }
    cout << ans;

    return 0;
}