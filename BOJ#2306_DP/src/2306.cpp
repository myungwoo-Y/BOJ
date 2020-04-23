#include <bits/stdc++.h>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#define MAX 987654321
#define MIN -987654321
#include <ctype.h>

using namespace std;
const string endL = "\n";
vector<vector<int>> arr;
vector<vector<int>> cache;
vector<vector<int>> dp;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    string dna;
    cin >> dna;
    int dna_len = dna.length();
    dp.resize(dna_len, vector<int>(dna_len));
    for (int len = 2; len <= dna_len; ++len) {
        for (int s = 0; s < dna_len-1; ++s) {
            int e = s+len-1;
            if(e >= dna_len)
                break;
            for (int step = 0; step < e-1; ++step) {
                int k = s+step;
                if(k == e)
                    break;
                dp[s][e] = max(dp[s][k]+dp[k+1][e], dp[s][e]);
            }
            if((dna.at(s) == 'a' && dna.at(e) == 't')
                || (dna.at(s) == 'g' && dna.at(e) == 'c')){
                dp[s][e] = max(dp[s+1][e-1]+2, dp[s][e]);
            }
        }
    }

    int maxValue = 0;
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[0].size(); ++j) {
            maxValue = dp[i][j] > maxValue ? dp[i][j] : maxValue;
        }
    }

    cout << maxValue;

    return 0;
}