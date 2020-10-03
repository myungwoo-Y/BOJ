// based by https://codeforces.com/blog/entry/18051
// 초간단 반복문형 세그먼트 트리!
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