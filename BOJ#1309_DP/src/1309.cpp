#include <bits/stdc++.h>
#include <queue>
#include <stdio.h>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
const int MAX = 987654321;
const int MIN = -987654321;
bool indexCheck(int r, int c, int rowSize, int colSize){
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}
const char endL = '\n';

using namespace std;

int dp[100001][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    int n {};
    int divideValue = 9901;
    cin >> n;

    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;

    for (int i = 1; i < n; ++i) {
        // 아에 없는 경우
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%divideValue;
        // 왼쪽
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%divideValue;
        // 오른쪽
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%divideValue;
    }

    int lastIdx = n-1;

    cout << (dp[lastIdx][0] + dp[lastIdx][1] + dp[lastIdx][2])%divideValue;

    return 0;
}


