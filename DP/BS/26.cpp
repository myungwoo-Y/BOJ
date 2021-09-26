int solve(string s){
    string rs = s;
    int l = s.length();
    reverse(rs.begin(), rs.end());
    
    int dp[1001][1001] = {0};
    
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            if(s[i-1] == rs[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[l][l];
}
