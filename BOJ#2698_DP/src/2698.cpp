#include <bits/stdc++.h>
#define VII vector<vector<int>>
#define VDD vector<vector<double>>
#define VCC vector<vector<char>>
#define VSS vector<vector<string>>
#define VBB vector<vector<bool>>
#define VLL vector<vector<long long>>
#define VI vector<int>
#define VB vector<bool>
#define VS vector<string>
#define VC vector<char>
#define VD vector<double>
#define VL vector<long long>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#define MAX 987654321
#define MIN -987654321
#include <ctype.h>

using namespace std;
const string endL = "\n";
int n, k;
int dp[100][100][2];

int search(int idx, int cnt, int lastBit){
    if(cnt == k && idx >= n)
        return 1;

    if(idx >= n || cnt > k)
        return 0;

    int& ret = dp[idx][cnt][lastBit];
    if(ret != -1)
        return ret;

    ret = 0;

//    if(idx == n-1 && (cnt == k-1 || cnt == k)){
//        ret = 1;
//        return ret;
//    }

    ret += search(idx+1, cnt, 0);
    ret += search(idx+1, cnt+(lastBit==1), 1);

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
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));

        cout << search(0, 0, 0) << endL;
    }

    return 0;
}