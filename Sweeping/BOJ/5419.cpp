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

const int LimitArr = 1e6;
struct SegTree{
    int leafSize;
    int tree[LimitArr * 2];

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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    int testCase;
    cin >> testCase;

    loop(testCase){
        int n {};
        LL ans {};
        vector<pii> points;
        set<set<pii>> s;

        cin >> n;
        SegTree sg(n);


        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }

        sort(points.begin(), points.end(), [](pii& a, pii& b){
            return a.second < b.second;
        });

        int order = 0;
        vector<int> orders(n);

        // y좌표 최신값 게산하기
        for (int i = 1; i < points.size(); ++i) {
            order += points[i].second > points[i-1].second;
            orders[i] = order;
        }

        // y좌표 실제로 바꿈
        for (int i = 0; i < points.size(); ++i) {
            points[i].second = orders[i];
        }

        // x좌표로 정렬
        sort(points.begin(), points.end(), [](pii& a, pii& b){
            if(a.first == b.first){
                return a.second > b.second;
            }else{
                return a.first < b.first;
            }
        });

        for (int i = 0; i < points.size(); ++i) {
            ans += sg.query(points[i].second, n);
            sg.update(points[i].second, 1);
        }
        cout << ans << endL;
    }

    return 0;
}



