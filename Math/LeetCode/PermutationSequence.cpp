// Title : 60. Permutation Sequence

class Solution {
public:
    
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> nums = {1};
        vector<int> facto = {1};

        for (int i = 1; i < n; i++) {
            facto.push_back(facto[i-1] * i);
            nums.push_back(i+1);
        }

        k--;

        for (int i = n-1; i >= 0; i--) {
            int idx = k/facto[i];
            k -= idx * facto[i];
            ans += string(1, '0'+nums[idx]);
            nums.erase(nums.begin()+idx);
        }

        return ans;
    }
};