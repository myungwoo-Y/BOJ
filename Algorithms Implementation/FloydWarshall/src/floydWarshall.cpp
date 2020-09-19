void floydWarshall (vector<vector<int>> graph) {
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
                if (cost[v][k] != -1 && cost[k][u] != -1
                    && cost[v][k] + cost[k][u] < cost[v][u]) {
                    cost[v][u] = cost[v][k] + cost[k][u];
                }
            }
            // negative cycle!!
            if (cost[v][v] < 0){
                return;
            }

        }
    }
}