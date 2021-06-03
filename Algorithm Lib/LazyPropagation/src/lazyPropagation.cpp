// based by https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220824350353&proxyReferer=https:%2F%2Fwww.google.com%2F

using namespace std;
const int ST_MAX = 1<<21;

struct SegTree{
    int start;
    long long tree[ST_MAX], lazy[ST_MAX];

    // 생성자
    SegTree(){
        start = ST_MAX/2;
        fill(tree, tree + ST_MAX, 0);
        fill(lazy, lazy+ST_MAX, 0);
    }

    // 리프 노드들의 값을 먼저 입력한 후 전체 세그먼트 트리 구축
    void construct(){
        for(int i=start-1; i>0; i--)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    // 구간 [l, ne)
    void propagate(int node, int l, int r){
        // lazy 값이 존재하면 실행
        if(lazy[node] != 0){
            // 리프 노드가 아니면 자식들에게 lazy 미룸
            if(node < start){
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            // 자신에 해당하는 만큼의 값을 더함
            tree[node] += lazy[node] * (r - l);
            lazy[node] = 0;
        }
    }

    // 구간 [s, e)에 k를 더하라
    void add(int l, int r, int k){
        add(l, r, k, 1, 0, start);
    }
    void add(int l, int r, int k, int node, int pl, int pr){
        // 일단 propagate
        propagate(node, pl, pr);

        if(r <= pl || pr <= l) return;
        if(l <= pl && pr <= r){
            // 이 노드가 구간에 완전히 포함되면 lazy 부여 후 propagate
            lazy[node] += k;
            propagate(node, pl, pr);
            return;
        }
        int mid = (pl + pr) / 2;
        add(l, r, k, node * 2, pl, mid);
        add(l, r, k, node * 2 + 1, mid, pr);
        // 마지막에 자식들의 값을 사용해 다시 자신의 값 갱신
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // 구간 [s, e)의 합을 구하라
    long long sum(int l, int r){
        return sum(l, r, 1, 0, start);
    }
    long long sum(int l, int r, int node, int pl, int pr){
        // 일단 propagate
        propagate(node, pl, pr);

        if(r <= pl || pr <= l) return 0;
        if(l <= pl && pr <= r) return tree[node];
        int mid = (pl + pr) / 2;
        return sum(l, r, node * 2, pl, mid) + sum(l, r, node * 2 + 1, mid, pr);
    }
};