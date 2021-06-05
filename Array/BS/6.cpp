// Special Product List
vector<int> solve(vector<int>& nums) {
    
    vector<int> sufProds(nums.size());
    // init value for index out
    sufProds.push_back(1);
    
    for (int i = nums.size()-1; i >= 0; --i) {
        sufProds[i] = sufProds[i+1] * nums[i];
    }
    
    vector<int> ans(nums.size());
    
    int preProd = 1;
    
    for (int i = 0; i < nums.size(); ++i) {
        ans[i] = preProd * sufProds[i+1];
        preProd *= nums[i];
    }
    
    return ans;
}