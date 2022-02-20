// 312. Burst Balloons

// Top-Down
class Solution {
public:
    int dp[302][302];
    int getMaxScore(int left, int right, vector<int>& nums) {
        if (left + 1 == right) return 0;
        
        int& ret = dp[left][right];
        
        if (ret != -1) return ret;
        
        ret = 0;
        for (int i = left + 1; i < right; i++) {
            int mul = nums[left] * nums[i] * nums[right];
            ret = max(ret, mul + getMaxScore(left, i, nums) + getMaxScore(i, right, nums));
        }
        
        return ret;
        
    }
    
    int maxCoins(vector<int>& nums) {
        int ret = 0;
        fill_n(&dp[0][0], 302 * 302, -1);
        
        int n = nums.size() + 2;
        
        vector<int> paddingNums(n);
        
        paddingNums[0] = paddingNums[n-1] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            paddingNums[i+1] = nums[i];
        }
        
        ret = getMaxScore(0, n-1, paddingNums);
        
        return ret;
    }
};


// Bottom-Up
class Solution {
public:
    int dp[302][302];

    
    int maxCoins(vector<int>& nums) {
        int ret = 0;
        fill_n(&dp[0][0], 302 * 302, 0);
        
        int n = nums.size() + 2;
        
        vector<int> paddingNums(n);
        
        paddingNums[0] = paddingNums[n-1] = 1;
        for (int i = 0; i < nums.size(); i++) {
            paddingNums[i+1] = nums[i];
        }
        
        for (int len = 3; len <= n; len++) {
            for (int left = 0; left < n; left++) {
                int right = left + len - 1;
                if (right >= n) break;
                for (int bursted = left+1; bursted < right; bursted++) {
                    int sum = paddingNums[left] * paddingNums[bursted] * paddingNums[right];
                    dp[left][right] = max(dp[left][right], sum + dp[left][bursted] + dp[bursted][right]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
