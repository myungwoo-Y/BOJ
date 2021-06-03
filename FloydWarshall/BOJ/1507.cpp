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


int floydWarshall (vector<vector<int>> graph) {
    int N = graph.size();
    vector<vector<int>> cost(N, vector<int>(N));

    for (int v = 0; v < N; v++) {
        for (int u = 0; u < N; u++) {
            cost[v][u] = graph[v][u];
        }
    }
    for (int k = 0; k < N; k++) {
        for (int v = 0; v < N; v++) {
            for (int u = 0; u < N; u++) {
                if(v == k || u == k)
                    continue;
                if (graph[v][k] + graph[k][u] == graph[v][u]) {
                    cost[v][u] = 0;
                }else if(graph[v][k] + graph[k][u] < graph[v][u]){
                    return -1;
                }
            }

        }
    }
    int sum {};
    for (int v = 0; v < N; ++v) {
        for (int u = v+1; u < N; ++u) {
            sum += cost[v][u];
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    int size {};
    cin >> size;
    vector<vector<int>> graph(size);

    for (int v = 0; v < size; ++v) {
        for (int u = 0; u < size; ++u) {
            int time {};
            cin >> time;
            graph[v].push_back(time);
        }
    }

    cout << floydWarshall(graph);


    return 0;
}



