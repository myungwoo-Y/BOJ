// Remove Interval Overlaps
int solve(vector<vector<int>>& intervals) {
    
    int ret = 0;
    
    if(intervals.size() == 0) return ret;
    
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) -> bool {
        return a[1] < b[1];
    });
    
    int cur = intervals[0][1];
    
    for(int i = 1; i < intervals.size(); i++){
        if(cur <= intervals[i][0]){
            cur = intervals[i][1];
        }else{
            ret++;
        }
    }
    
    
    return ret;
}