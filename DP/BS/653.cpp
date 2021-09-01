// Create Palindrome After Deleting at Most K Characters
// About LSC
bool solve(string s, int k) {
    
    string a = s;
    reverse(s.begin(), s.end());
    string b = s;
    
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));
    
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return s.length() - dp[a.length()][b.length()] <= k;
}