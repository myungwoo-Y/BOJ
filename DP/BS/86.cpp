// Break String Into Words

bool solve(vector<string>& words, string s) {
    vector<bool> dp = vector<bool>(s.length()+1);
    
    dp[0] = 1;
    
    for(int i = 0; i < s.length(); i++){
        for(auto& word : words){
            if(dp[i]){
                if(word.compare(s.substr(i, word.length())) == 0) dp[i+word.length()] = 1;
            }
        }
    }
    
    return dp[s.length()];
}