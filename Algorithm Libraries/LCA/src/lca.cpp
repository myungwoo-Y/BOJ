// based by https://m.blog.naver.com/kks227/220820773477

#include <bits/stdc++.h>
#include <stdio.h>

const char endL = '\n';

using namespace std;

const int MaxHeight = 20;  // 트리의 최대 높이 항상 고
int N, M;
int parents[100001][MaxHeight]; // parent[i][k]: i의 2^k번째 부모
int depths[100001]; // 정점의 깊이 (루트의 깊이: 0)
vector<int> adj[100001]; // 인접 리스트

// 루트 노드부터
// dfs로 트리 제작하며 parent[i][0], depth 배열 채움
void makeTreeByDFS(int cur){
    for(int u: adj[cur]){
        if(depths[u] == -1){
            parents[u][0] = cur;
            depths[u] = depths[cur] + 1;
            makeTreeByDFS(u);
        }ㅏ
    }
}

int findLCA(int u, int v){
    // depth[u] >= depth[v]가 되도록 필요에 따라 u, v를 스왑
    if(depths[u] < depths[v]) swap(u, v);
    int diff = depths[u] - depths[v];

    // 깊이 차(diff)를 없애며 u를 이동시킴
    for(int j=0; diff; j++){
        if(diff % 2 || diff == 1)
            u = parents[u][j];
        diff /= 2;
    }

    // u와 v가 다르면 동시에 일정 높이만큼 위로 이동시킴
    if(u != v){
        // 최대 높이 - 1 부터 실행
        for(int j= MaxHeight - 1; j >= 0; j--){
            if(parents[u][j] != -1 && parents[u][j] != parents[v][j]){
                u = parents[u][j];
                v = parents[v][j];
            }
        }
        // 마지막엔 두 정점 u, v의 부모가 같으므로 한 번 더 올림
        u = parents[u][0];
    }

    return u;
}


// 사용하기
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    cin >> N;
    for (int i = 0; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(parents, -1, sizeof(parents));
    memset(depths, -1, sizeof(depths));
    depths[1] = 0;

    // 트리 depth 채우기
    makeTreeByDFS(1);

    // parents 배열 채우기
    // node가 1부터 시작이니 i는 1부터 시작한다.
    for (int k = 0; k < MaxHeight; ++k) {
        for (int i = 1; i <= N; ++i) {
            if(parents[i][k] != -1){
                parents[i][k+1] = parents[parents[i][k]][k];
            }
        }
    }

    cin >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        cout << findLCA(u, v) << endL;
    }



    return 0;
}



