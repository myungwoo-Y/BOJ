// 828. Count Unique Characters of All Substrings of a Given String

class Solution {
public:
    
    int uniqueLetterString(string s) {
        // [0]: , [1]:  
        int dp[26][2];
        fill_n(&dp[0][0], sizeof(dp)/4, -1);
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            int c = s[i] - 'A';

            ret = ret + (i - dp[c][1]) * (dp[c][1] - dp[c][0]);

            dp[c][0] = dp[c][1];
            dp[c][1] = i;
        }

        for (int i = 0; i < 26; i++) {
            ret = ret + (s.length() - dp[i][1]) * (dp[i][1] - dp[i][0]);
        }
        
        return ret;
    }
};
