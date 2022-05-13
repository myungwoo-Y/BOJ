// 878. Nth Magical Number

class Solution {
public:
    int mod = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        int s = min(a, b), l = max(a, b);
        long lcm = a*b/gcd(l, s);
        int step = lcm/a + lcm/b - 1;

        int q = n / step;
        int r = n % step;
        long ret = (q * lcm) % mod;
        if (!r) {
            return ret;
        }

        vector<long> nums = {a, b};
        for (int i = 0; i < r-1; i++) {
            int idx = nums[0] < nums[1] ? 0 : 1;
            int val = idx == 0 ? a : b;
            nums[idx] += val;
        }
        
        ret += min(nums[0], nums[1]) % mod;
        ret %= mod;
        return ret;
    }

    // a > b
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a%b);
        }
    }
};