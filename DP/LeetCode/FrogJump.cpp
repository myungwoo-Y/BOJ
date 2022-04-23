// 403. Frog Jump

class Solution {
public:
    // -1 : not visited, 0 : false, 1 : true
    vector<vector<int>> dp;
    
    bool search(int k, int cur, vector<int>& stones) {
        if (cur == stones.size()-1) {
            return 1;
        }
        
        if (dp[k][cur] != -1) {
            return dp[k][cur];
        }

        vector<int> jumps = {k-1, k, k+1};

        int& ret = dp[k][cur];
        ret = 0;

        for (int i = cur+1; i < stones.size(); i++) {
            bool canJump = false;
            for (int jump : jumps) {
                if (stones[i] == stones[cur] + jump) {
                    canJump = true;
                    break;
                }
            }
            if (canJump && !ret) {
                ret |= search(stones[i] - stones[cur], i, stones);
            }
        }

        return ret;
    }
    
    bool canCross(vector<int>& stones) {
        dp.assign(2001, vector<int>(2001, -1));
        if (stones[1] > 1) return false;
        return search(1, 1, stones);
    }
};