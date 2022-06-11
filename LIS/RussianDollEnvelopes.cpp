// 354. Russian Doll Envelopes

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> heights;
        
        sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b) -> bool{
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });
        
        
        for (auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }
        
        return getLIS(heights);        
    }
    
    int getLIS(vector<int>& nums) {
        
        vector<int> dp;
        dp.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) {
                dp.push_back(num);
            } else {
                int idx = it - dp.begin();
                dp[idx] = num;
            }
        }
        
        return dp.size();        
    }
};