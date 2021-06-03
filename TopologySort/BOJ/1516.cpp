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
#define vertextMax 501

int n;
int indegrees[vertextMax];
int delays[vertextMax];
vector<int> graph[vertextMax];
vector<int> result;


void topologySort() {
    bool isCycle = false;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 1; i <= n; i++) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (q.empty()) {
            isCycle = true;
            return;
        }
        int cur = q.top();
        q.pop();
        result.push_back(cur);

        for (auto near : graph[cur]) {
            if (--indegrees[near] == 0) {
                q.push(near);
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

    cin >> n;

    for (int vertex = 1; vertex <= n; ++vertex) {
        int delay {};
        cin >> delay;
        delays[vertex] = delay;
        int prev {};
        while(cin >> prev){
            if(prev == -1){
                break;
            }else{
                graph[prev].push_back(vertex);
                indegrees[vertex]++;
            }
        }
    }

    topologySort();

    vector<int> totalTimes(n+1, 0);

    for(auto v : result){
        totalTimes[v] += delays[v];
        for (auto next : graph[v]) {
            totalTimes[next] = max(totalTimes[next], totalTimes[v]);
        }
    }

    for (int i = 1; i < totalTimes.size(); ++i) {
        cout << totalTimes[i] << endL;
    }

    return 0;
}


