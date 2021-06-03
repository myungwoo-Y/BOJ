#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>

#define LL long long int
#define loop(n) for(int I = 0; I < n; ++I)
#define sz(x) (int)x.size()
#define ALPHA 26
#define pii pair<int,int>
const int MAX = 987654321;
const int MIN = -987654321;
const int MaxPos = 75001;

const char endL = '\n';

using namespace std;

vector<vector<int>> table;

vector<vector<int>> graph;

int rowN, colN, labelN = 1;

vector<vector<int>> dirs = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
};

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
        if(edges.empty()){
            return {{0, 0, -1}};
        }

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

void labelDFS(int r, int c){
    if(table[r][c] != -1)
        return;
    table[r][c] = labelN;

    for(auto dir : dirs){
        int newR = r + dir[0];
        int newC = c + dir[1];
        if(table[newR][newC] == -1){
            labelDFS(newR, newC);
        }
    }
}

struct D{
    int r, c, cnt, dir;
};

void minDistBFS(int r, int c, int label){
    queue<D> q;
    q.push({r, c});
    bool visited[20][20];
    memset(visited, 0, 400);
    visited[r][c] = true;

    while(!q.empty()){
        D cur = q.front();
        q.pop();

        // 바다에서의 이
        if(table[cur.r][cur.c] == 0){
            auto dir = dirs[cur.dir];
            auto [newR, newC] = make_pair(cur.r + dir[0], cur.c + dir[1]);
            if(table[newR][newC] != MIN){
                q.push({newR, newC, cur.cnt+1, cur.dir});
            }

        // 다른섬에 도달 했을 경우
        }else if(table[cur.r][cur.c] > 0 && table[cur.r][cur.c] != label){
            int other = table[cur.r][cur.c];
            if(cur.cnt == 1)
                continue;
            graph[label][other] = min(graph[label][other], cur.cnt);

        // 자기 섬 내에서의 이동
        }else if(cur.cnt == 0){
            for(int i = 0; i < dirs.size(); i++){
                auto dir = dirs[i];
                auto [newR, newC] = make_pair(cur.r + dir[0], cur.c + dir[1]);
                if(!visited[newR][newC]
                   && table[newR][newC] != MIN){
                    q.push({newR, newC, cur.cnt, i});
                    visited[newR][newC] = true;
                }
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

    cin >> rowN >> colN;

    table.resize(rowN+2, vector<int>(colN+2, MIN));

    // 테이블 생성
    for (int i = 1; i <= rowN; ++i) {
        for (int j = 1; j <= colN; ++j) {
            int value;
            cin >> value;
            table[i][j] = value == 1 ? -1 : 0;
        }
    }

    // 라벨링 실행!
    for (int i = 1; i <= rowN ; ++i) {
        for (int j = 1; j <= colN; ++j) {
            if(table[i][j] == -1){
                labelDFS(i, j);
                labelN++;
            }
        }
    }

    // 라벨링 한거 바탕으로 사이즈 알아내서 그래프 리사이즈
    graph.resize(labelN, vector<int>(labelN, MAX));

    // 두 그래프간 거리 구하기
    for (int i = 1; i <= rowN ; ++i) {
        for (int j = 1; j <= colN; ++j) {
            if(table[i][j] > 0){
                minDistBFS(i, j, table[i][j]);
            }
        }
    }

    // 그래프 엣지로 변환
    vector<Edge> edges;
    for (int v = 1; v < labelN; ++v) {
        for (int u = v+1; u < labelN; ++u) {
            if(graph[v][u] != MAX && graph[v][u] > 1){
                edges.push_back({v, u, graph[v][u]});
            }
        }
    }

    if(edges.empty()){
        cout << -1;
    }else{
        auto ret = kruskal(edges, labelN-1);

        int ans = 0;

        for(auto edge : ret){
            ans += edge.weight;
        }

        cout << ans;
    }


    return 0;
}



