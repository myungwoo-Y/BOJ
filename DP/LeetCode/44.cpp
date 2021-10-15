// Wildcard Matching

// use dp
// top down ? or bottom up
// first of all, use top down -> if it is impossible, use bottom up
// bottom-up is oppisite direction of top-down

// fn(a, b, dp)

// * case
// 1. emtpy
// 2. match and increase idx
// 3. match but not increase idx

class Solution {
public:
    bool visited[2000][2000];
    int l;
    bool search(int a, int b, string& s, string& p, vector<vector<bool>>& dp){
        
        if(a == s.length() && b == p.length()){
            return true;
        }else if(b >= p.length()){
            return false;
        }else if(a >= s.length()){
            if(p[b] == '*') return search(a, b+1, s, p, dp);
            else return false;
        }
        
        if(visited[a][b]) return dp[a][b];
        
        visited[a][b] = true;
        
        if(s[a] == p[b] || p[b] == '?'){
            dp[a][b] = search(a+1, b+1, s, p, dp);
        }else if(p[b] == '?'){
        }else if(p[b] == '*'){
            // as empty
            bool res = search(a, b+1, s, p, dp);
            // as match and move to next pattern
            if(!res) res = search(a+1, b+1, s, p, dp);
            // as match but not move to next pattern
            if(!res) res = search(a+1, b, s, p, dp);
        
            dp[a][b] = res;
        }else{
            dp[a][b] = false;
        }
        
        return dp[a][b];
    }
    
    bool isMatch(string s, string p) {
        
        vector<vector<bool>> dp(s.length(), vector<bool>(p.length(), false));
        
        return search(0, 0, s, p, dp);
        
    }
};