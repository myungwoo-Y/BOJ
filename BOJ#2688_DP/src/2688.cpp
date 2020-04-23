#include <bits/stdc++.h>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#define MAX 987654321
#define MIN -987654321
#include <ctype.h>

using namespace std;
const char endL {'\n'};

int digitN;
LL cache[65][10];
LL search(int idx, int n){
    if(idx == digitN-1)
        return 1;

    LL& ret = cache[idx][n];
    if(ret != -1)
        return ret;

    ret = 0;
    for (int newN = n; newN < 10; ++newN) {
        ret += search(idx+1, newN);
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int testCase {};
    cin >> testCase;
    loop(testCase){
        memset(cache, -1, sizeof(cache));
        cin >> digitN;
        LL ans {};
        for (int n = 0; n < 10; ++n) {
            ans += search(0, n);
        }
        cout << ans << endL;
    }
    return 0;
}