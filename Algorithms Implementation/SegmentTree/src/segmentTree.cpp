// based by https://codeforces.com/blog/entry/18051
// 초간단 반복문형 세그먼트 트리!
// 이 트리는 트리 사이즈가 2의 지수승이 아니어도 동작한다.


// 구조체 버전
const int LimitArr = 1e6;
struct SegTree{
    int leafSize;
    int t젼ree[LimitArr * 2];

    SegTree(int size){
        memset(tree, 0, LimitArr * 2);
        leafSize = size;
    }

    void init() {
        for (int i = leafSize - 1; i > 0; i--){
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

    int query(int l, int r) {
        int res = 0;
        for (l += leafSize, r += leafSize; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }

    void update(int pos, int val) {
        tree[pos + leafSize] += val; // update
        for (pos += leafSize; pos > 1; pos >>= 1) {
            tree[pos >> 1] = tree[pos] + tree[pos ^ 1]; // update by rule
        }
    }
};


// 구조체 x 버
const int TreeN = 1e5;
int n;
int tree[TreeN * 2];

void init() {
    for (int i = n - 1; i > 0; i--){
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
}

// [l, r) 에 주의!
int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += tree[l++];
        if (r & 1) res += tree[--r];
    }
    return res;
}

void update(int pos, int val) {
    tree[pos + n] = val; // update
    for (pos += n; pos > 1; pos >>= 1) {
        tree[pos >> 1] = tree[pos] + tree[pos ^ 1]; // update by rule
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
    init();
    update(0, 1);
    printf("%d\n", query(3, 11));
    return 0;
}