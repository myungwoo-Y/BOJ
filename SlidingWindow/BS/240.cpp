// Minimum Window Substring
// https://binarysearch.com/problems/Minimum-Window-Substring
int solve(string a, string b) {
    
    if(a.length() == 0) return -1;
    
    int l = 0, r = 0, cnt = 0, ret = INT32_MAX, len = 0;
    
    unordered_map<char, int> contains;
    unordered_map<char, int> req;
    
    for(auto ch : b){
        if(req.find(ch) != req.end())
            req[ch]++;
        else
            req[ch] = 1;
    }
        
    
    for(auto ch : a){
        if(req.find(ch) != req.end())
            contains[ch] = 0;
    }
    
    if(req.find(a[0]) != req.end()){
        contains[a[0]] = 1;
        cnt++;
    }
    
    len = 1;
    
    while(l <= r){
        // required
        if(cnt == b.length()){
            ret = min(ret, len);
            
            // contract logic
            char ch = a[l];
            if(req.find(ch) != req.end()){
                cnt -= contains[ch] == req[ch];
                contains[ch]--;
            }
            l++;
            len--;
        }else if(r+1 < a.length()){
            len++;
            r++;
            char ch = a[r];
            
            if(req.find(ch) != req.end()){
                cnt += contains[ch] < req[ch];
                contains[ch]++;
            }
        }else
            break;
    }
    
    return ret == INT32_MAX ? -1 : ret;
}