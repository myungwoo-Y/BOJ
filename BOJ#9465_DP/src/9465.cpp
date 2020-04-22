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
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int testCase;
    cin >> testCase;
    loop(testCase){
        int n {};
        cin >> n;
        arr = vector<vector<int>>(2, vector<int>(n));
        cache = vector<vector<int>>(2, vector<int>(n));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
                cache[i][j] = arr[i][j];
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < 2; ++i) {
                int left {}, downLeft {}, down {};
                if(i == 0){
                    if(j > 1){
                        left += cache[i][j-2];
                        downLeft += cache[i+1][j-2];
                    }
                    if(j > 0)
                        down += cache[i+1][j-1];

                }else if(i == 1){
                    if(j > 1){
                        left += cache[i][j-2];
                        downLeft += cache[i-1][j-2];
                    }
                    if(j > 0)
                        down += cache[i-1][j-1];
                }
                cache[i][j] = max({left, downLeft, down}) + arr[i][j];
            }
        }

        int maxValue = 0;
        for (int i = 0; i < cache.size(); ++i) {
            for (int j = 0; j < cache[0].size(); ++j) {
                if(cache[i][j] > maxValue)
                    maxValue = cache[i][j];
            }
        }
        cout << maxValue << endL;

    }
    return 0;
}