struct Edge {
    int src, dest, weight;
};

struct DisjointSet{
    vector<int> parent;
    vector<int> counts;
    DisjointSet(int size): parent(size), counts(size, 1){
        for(int i = 0; i < parent.size(); i++)
            parent[i] = i;
    }
    int find(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    int merge(int a, int b){
        int parentA = find(a), parentB = find(b);
        if(parentA == parentB)
            return counts[parentA];
        else{
            if(counts[parentB] > counts[parentA]){
                counts[parentB] += counts[parentA];
                parent[parentA] = parentB;
                return counts[parentB];
            }else{
                counts[parentA] += counts[parentB];
                parent[parentB] = parentA;
                return counts[parentA];
            }
        }
    }
};

vector<Edge> kruskal(vector<Edge> edges, int N)
{
    // 원래는 오름차순이지만 vector back을 사용하기 위해 내림차순으로 정렬
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) -> bool{
        return  a.weight > b.weight;
    });

    vector<Edge> mst;

    DisjointSet ds(N+1);


    // MST는 V-1의 간선을 갖는다
    while (mst.size() != N - 1)
    {
        Edge next_edge = edges.back();
        edges.pop_back();

        int x = ds.find(next_edge.src);
        int y = ds.find(next_edge.dest);

        // 사이클을 형성하지 않음을 확인
        if (x != y)
        {
            mst.push_back(next_edge);
            ds.merge(x, y);
        }
    }
    return mst;
}
