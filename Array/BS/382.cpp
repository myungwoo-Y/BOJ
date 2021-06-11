// Selling Products
int solve(vector<int>& items, int n) {
    unordered_map<int, int> m;
    
    for(int item : items){
        m[item]++;
    }
    
    vector<int> countArr;
    
    for(const auto & [k, v] : m){
        countArr.push_back(v);
    }
    
    sort(countArr.begin(), countArr.end());
    
    int ans = 0;
    for(auto v : countArr){
        if(n-v >= 0){
            n -= v;
        }else{
            ans++;
        }
    }
    
    return ans;
}