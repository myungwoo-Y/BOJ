// 315. Count of Smaller Numbers After Self

class Solution {
public:
    vector<int> tree;
    int size = 1;
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> positions;
        tree.assign(nums.size()+1, 0);
        vector<int> idxs;
        vector<int> ret;
        unordered_map<int, int> m;
        unordered_map<int, int> cntMap;

        for (int i = 0; i < nums.size(); i++) {
            if (cntMap.find(nums[i]) == cntMap.end()) {
                size++;
                positions.push_back({size-1, nums[i]});
            }
            cntMap[nums[i]]++;
        }
        
        sort(positions.begin(), positions.end(), [](auto& a, auto& b) -> bool {
            return a.second < b.second;
        });

        for (int i = 0; i < positions.size(); i++) {
            m[positions[i].second] = i;
            update(i, cntMap[positions[i].second]);
        }
        

        for (int i = 0; i < nums.size(); i++) {
            int idx = m[nums[i]];
            if (idx > 0) {
                ret.push_back(getSum(idx-1));
            } else {
                ret.push_back(0);
            }
            update(idx, -1);
        }

        return ret;
    }

    int getSum(int idx) {
        int sum = 0;
        for (int i = idx+1; i >= 1; i -= i&(-i)) {
            sum += tree[i];
        }
        return sum;
    }

    void update(int idx, int diff) {
        for (int i = idx+1; i < tree.size(); i += i&(-i)) {
            tree[i] += diff;
        }
    }
};