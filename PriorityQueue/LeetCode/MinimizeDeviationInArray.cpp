// 1675. Minimize Deviation in Array

class Solution {
public:
    priority_queue<int> q;
    unordered_map<int, int> m;
    int minimumDeviation(vector<int>& nums) {
        int ret = INT_MAX, minNum = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                nums[i] *= 2;
            }
        }

        for (int num : nums) {
            minNum = min(minNum, num);
            m[num]++;
            q.push(num);
        }

        while (!q.empty()) {
            int t = q.top();
            q.pop();

            m[t]--;

            if (t == minNum && m[t] > 0) {
                ret = 0;
                break;
            }

            ret = min(ret, t - minNum);

            if (t % 2 == 0) {
                int newNum = t/2;
                minNum = min(minNum, newNum);
                q.push(newNum);
                m[newNum]++;
            } else {
                break;
            }
        }

        return ret;
    }
};