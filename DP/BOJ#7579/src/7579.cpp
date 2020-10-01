#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>

#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#define sz(x) (int)x.size()
#define ALPHA 26
const int MAX = 987654321;
const int MIN = -987654321;

const char endL = '\n';

using namespace std;

int n,m;

struct App{
    int m, c;
};

int dp[101][10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    int ans = MAX;

    cin >> n >> m;

    vector<App> apps(n+1);

    for (int i = 1; i <= n; ++i) {
        cin >> apps[i].m;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> apps[i].c;
    }

    for (int i = 1; i <= n; ++i) {
        for (int cost = 0; cost <= 10000; ++cost) {
            if(cost - apps[i].c >= 0){
                dp[i][cost] = max(dp[i-1][cost], dp[i-1][cost - apps[i].c] + apps[i].m);
            }else{
                dp[i][cost] = dp[i-1][cost];
            }
            if(dp[i][cost] >= m){
                ans = min(ans, cost);
            }
        }
    }

    cout << ans;
    return 0;
}



