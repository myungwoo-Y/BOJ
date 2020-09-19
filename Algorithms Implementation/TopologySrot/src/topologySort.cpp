//
// Created by 양명우 on 2020/09/19.
//

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