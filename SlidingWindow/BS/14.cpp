// Sliding Window Max

vector<int> solve(vector<int>& nums, int k) {
    vector<int> ans;
    set<int, greater<int>> s;
    unordered_map<int, int> m;
    
    int l = 0, r = k-1;
    
    for (int i = 0; i < k; ++i) {
        int v = nums[i];
        s.insert(v);
        m[v]++;
    }
    
    ans.push_back(*s.begin());
    
    while(r < nums.size()-1){
        r++;
        
        int v = nums[r];
        int rm = nums[l];
        s.insert(v);
        m[v]++;
        
        s.erase(rm);
        m[rm]--;
        if(m[rm] > 0){
            s.insert(rm);
        }
        
        ans.push_back(*s.begin());
        
        l++;
    }
    
    return ans;
}