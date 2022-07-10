class Solution {
public:
    unordered_map<int, int> getCounter(vector<int>& arr) {
        unordered_map<int, int> ret;
        for (auto n : arr) {
            ret[n]++;
        }
        return ret;
    }
    
    vector<int> dfs(int n, vector<int>& sums) {
        vector<vector<int>> cands;
        auto counter = getCounter(sums);

        int d = sums[1] - sums[0];
        
        for (int sig : {-1, 1}) {
            vector<int> cand;
            int originDiff = d * sig;
            for (int s : sums) {
                if (counter.find(s) == counter.end()
                   || !counter[s]) continue;
                if (counter.find(s - originDiff) == counter.end()
                   || !counter[s - originDiff]) break;
                
                counter[s]--;
                counter[s - originDiff]--;
                cand.push_back(s);
            }
            
            if (1 << (n-1) == cands.size()) {
                cand.push_back(d * sig);
                if (sig == 1) {
                    reverse(cand.begin(), cand.end());
                    reverse(sums.begin(), sums.end());
                }
                cands.push_back(dfs(n-1, cand));
            }
            
        }
        
        return cands;
    }
    
    vector<int> recoverArray(int n, vector<int>& sums) {
        
        
        sort(sums.begin(), sums.end());
        
        
        
        
    }
};