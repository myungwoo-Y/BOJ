class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int totalTime = 0;
        vector<int> counts(26);
        
        for (char task : tasks) {
            counts[task - 'A']++;
        }
        
        sort(counts.begin(), counts.end(), greater<int>());
        
        int idleTime = (counts[0] - 1) * n;
        
        for (int i = 1; i < counts.size(); i++) {
            if (counts[i] == 0) break;
            idleTime -= min(counts[0]-1, counts[i]);
        }
        
        idleTime = max(0, idleTime);
        
        totalTime = idleTime + tasks.size();
        
        return totalTime;
    }
};