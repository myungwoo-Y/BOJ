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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    int size {};
    cin >> size;
    vector<vector<int>> graph(size, vector<int>(size));

    for (int v = 0; v < size; ++v) {
        string relation = "";
        cin >> relation;
        for (int i = 0; i < relation.length(); ++i) {
            if(i == v)
                graph[i][v] = 0;
            int value = relation[i] == 'Y' ? 1 : MAX;
            graph[v][i] = value;
            graph[i][v] = value;
        }
    }

    floydWarshall(graph);


    return 0;
}



