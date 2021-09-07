// Painting Houses
int solve(vector<vector<int>>& matrix) {
    
    int n = matrix.size(), k = matrix[0].size();
    
    int dp[n][k];
    
    for (int i = 0; i < k; i++) {
        dp[0][i] = matrix[0][i];
    }
    
    // fill the DP table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            dp[i][j] = INT32_MAX;
            for (int t = 0; t < k; t++) {
                if(j == t) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][t] + matrix[i][j]);
            }
        }
    }
    
    return *min_element(dp[n-1], dp[n-1] + k);
    
}