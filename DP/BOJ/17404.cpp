// RGB거리 2
vector<vector<int>> colors;

int main() {

    int n {};
    int ans = MAX;
    const int colorN = 3;
        
    cin >> n;

    colors = vector<vector<int>>(n, vector<int>(n));

    for(int i = 0; i < n; ++i){
        for (int j = 0; j < colorN; ++j) {
            cin >> colors[i][j];
        }
    }

    for(int selectedIdx = 0; selectedIdx < colorN; ++selectedIdx){
        vector<vector<int>> dp(n, vector<int>(colorN, MAX));
        
        // init value in index 1
        for (int i = 0; i < colorN; ++i) {
            if(i == selectedIdx){
                dp[1][i] = MAX;
            }else{
                dp[1][i] = colors[0][selectedIdx] + colors[1][i];
            }
        }

        for(int i = 2; i < n; ++i){
            for(int j = 0; j < colorN; ++j){
                if(j == selectedIdx && i == n-1){
                    dp[i][j] = MAX;
                }else{
                    dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + colors[i][j];
                }
                
            }
        }

        ans = min({ans, dp[n-1][0], dp[n-1][1], dp[n-1][2]});

    }

    cout << ans;
    return 0;
}


