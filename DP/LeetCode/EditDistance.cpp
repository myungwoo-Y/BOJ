// Title : 72. Edit Distance
class Solution {
public:
    
    int dp[500][500];
    
    // find min dist
    int search(int si, int li, string& s, string& l){
        if(si == s.length()){
            return l.length() - li;
        }else if(li == l.length()){
            return s.length() - si;
        }
        
        int& ret = dp[si][li];
        
        if(ret != -1) return ret;
        
        ret = INT_MAX;
    
        if(s[si] == l[li])
            ret = min(ret, search(si+1, li+1, s, l));
        // replace
        ret = min(ret, search(si+1, li+1, s, l) + 1);
        // insert a char to large string
        ret = min(ret, search(si, li+1, s, l) + 1);
        // insert a char to small string
        ret = min(ret, search(si+1, li, s, l) + 1);
        return ret;
    }
    
    int minDistance(string word1, string word2) {
        
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        
        if(word1.length() == word2.length()){
            return search(0, 0, word1, word2);
        }else{
            string l = word1.length() > word2.length() ? word1 : word2;
            string s = l != word1 ? word1 : word2;
            return search(0, 0, s, l);
        }
    }
};