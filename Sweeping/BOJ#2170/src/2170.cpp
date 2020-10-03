#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>

#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#define sz(x) (int)x.size()
#define ALPHA 26
#define pii pair<int,int>
const int MAX = 987654321;
const int MIN = -987654321;

const char endL = '\n';

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    vector<pii> points;

    int n {};
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }

    sort(points.begin(), points.end());

    int ans = 0;

    int s = points.front().first;
    int e = points.front().second;
    for (int i = 1; i < n; ++i) {
        auto point = points[i];

        if(point.first <= e){
            e = max(e, point.second);
        }else{
            ans += e - s;
            s = point.first;
            e = point.second;
        }
    }
    ans += e - s;

    cout << ans;

    return 0;
}



