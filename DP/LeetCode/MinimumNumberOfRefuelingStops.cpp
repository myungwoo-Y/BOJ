// 871. Minimum Number of Refueling Stops

class Solution {
public:
    long dp[501];
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int stationNum = stations.size();
        
        dp[0] = startFuel;

        for (int i = 0; i < stationNum; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[j] >= stations[i][0]) {
                    dp[j+1] = max(dp[j+1], dp[j] + (long) stations[i][1]);
                }
            }
        }

        for (int i = 0; i <= stationNum; i++) {
            if (dp[i] >= target) return i;
        }

        return -1;
    }
};