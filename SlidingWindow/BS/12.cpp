// Longest Sublist with K Distinct Numbers
int solve(int k, vector<int>& nums) {
    
    int l = 0, r = 0;
    
    unordered_map<int ,int> m;
    
    int ret = 0;
    
    while(l <= r){
        if(m.size() > k){
            m[nums[l]]--;
            if(m[nums[l]] == 0)
                m.erase(nums[l]);
            l++;
        }else{
            if(r >= nums.size()) break;
            
            if(m.find(nums[r]) == m.end())
                m[nums[r]] = 1;
            else
                m[nums[r]]++;
            
            if(m.size() <= k){
                ret = max(r-l+1, ret);
            }
            
            r++;
        }
    }
    
    return ret;
}