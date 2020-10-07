struct Edge {
    int source, dest, weight;
};

struct Node {
    int vertex, weight;
};

vector<vector<Edge>> graph;


void print_route(vector<int> const &prev, int i)
{
if (i < 0)
return;

print_route(prev, prev[i]);
cout << i << " ";
}

struct comp
{
    bool operator()(Node &l, Node &r)
    {
        return l.weight > r.weight;
    }
};

void shortestPath(int source){
    int N = graph.size();
    priority_queue<Node, vector<Node>, comp> minHeap;
    minHeap.push({source, 0});

    vector<int> dist(N, INT_MAX);

    dist[source] = 0;

    vector<bool> done(N, false);
    done[source] = true;

    vector<int> prev(N, -1);

    while (!minHeap.empty()){
        // Remove and return best vertex
        Node node = minHeap.top();
        minHeap.pop();

        // get vertex number
        int v = node.vertex;

        // do for each neighbor v of v
        for (auto i : graph[v]){
            int u = i.dest;
            int weight = i.weight;

            // 더 짧은 거리를 알아냈을 경우 최신화!
            if (!done[u] && (dist[v] + weight) < dist[u]){
                dist[u] = dist[v] + weight;
                prev[u] = v;
                minHeap.push({u, dist[u]});
            }
        }

        done[v] = true;
    }

}
