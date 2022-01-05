// 1235. Maximum Profit in Job Scheduling
struct Job {
    int start, end, profit;
};

class Solution {
public:
    int dp[50001];
    
    // find max profit in position
    int getMax(vector<Job>& jobs, int pos) {
        if (pos >= jobs.size()) return 0;
        int& ret = dp[pos];
        
        if (ret != -1) return ret;
        
        Job& job = jobs[pos];
        
        int nextIdx = lower_bound(jobs.begin(), jobs.end(), jobs[pos].end, [](auto const& a, auto& value) -> bool {
            return a.start < value;
        }) - jobs.begin();
        
        int notSchedule = getMax(jobs, pos+1);
    
        // cannot select other job after shedule this job
        if (nextIdx >= jobs.size()) {
            ret = max(notSchedule, job.profit);
        } else {
            ret = max(notSchedule, getMax(jobs, nextIdx) + job.profit);
        }
        
        return ret;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<Job> jobs;
        
        for (int i = 0; i < startTime.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end(), [](auto& a, auto& b) -> bool { return a.start < b.start; });
        
        memset(dp, -1, sizeof(dp));
        
        return getMax(jobs, 0);
        
    }
};