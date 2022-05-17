// 829. Consecutive Numbers Sum

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        
        int limit = (int)(sqrt(2*n + 0.25) - 0.5);
        int ret = 0;
        
        for (int k = 1; k <= limit; k++) {
            double q = n - (double)k*(k+1)/2;
            if (fmod(q, k) == 0) {
                ret++;
            }
        
        }
            
        return ret;
    }
};