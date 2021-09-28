// A Student
int solve(vector<int>& deadlines, vector<int>& credits) {
    
    if(deadlines.size() == 0) return 0;
    
    int l = deadlines.size();
    
    vector<pair<int, int>> assigns;
    priority_queue<int> pq;
    
    for (int i = 0; i < l; i++) {
        assigns.push_back({deadlines[i], credits[i]});
    }
    
    sort(assigns.begin(), assigns.end());
    
    
    int sum = 0;
    int t = 10000;
    
    while(t >= 0){
        
        int i = assigns.size()-1;
        while(assigns[i].first == t){
            pq.push(assigns[i].second);
            assigns.pop_back();
            i--;
        }
        
        
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    
        
        --t;
    }
    
    return sum;
}