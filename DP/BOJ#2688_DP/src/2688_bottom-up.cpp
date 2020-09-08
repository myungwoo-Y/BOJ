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
LL cache[66][10];
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

    memset(cache, 0, sizeof(cache));
    for (int i = 0; i < 10; ++i) {
        cache[1][i] = i+1;
    }
    for (int i = 2; i <= 64; ++i) {
        LL sum {};
        for (int j = 0; j < 10; ++j) {
            cache[i][j] = cache[i-1][j] + sum;
            sum += cache[i-1][j];
        }
    }
    loop(testCase){
        cin >> digitN;
        cout << cache[digitN][9] << endL;
    }
    return 0;
}