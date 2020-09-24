// Data structure to store graph edges
struct Edge {
    int src, dest, weight;
};

class DisjointSet
{
    unordered_map<int, int> parent;
public:
    void initSet(int N)
    {
        for (int i = 0; i < N; i++)
            parent[i] = i;
    }

    int find(int k)
    {
        if (parent[k] == k)
            return k;
        return find(parent[k]);
    }

    void merge(int a, int b)
    {
        int x = find(a);
        int y = find(b);

        parent[x] = y;
    }
};

vector<Edge> kruskal(vector<Edge> edges, int N)
{
    // 원래는 오름차순이지만 vector back을 사용하기 위해 내림차순으로 정
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) -> bool{
        return  a.weight > b.weight;
    });

    vector<Edge> mst;

    DisjointSet ds;

    ds.initSet(N);

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