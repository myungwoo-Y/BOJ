// Next Integer Permutation

int solve(int n) {
    string s = to_string(n);

    int increaseIdx = -1;
    for(int i = s.length()-1; i > 0; --i){
        if(s[i-1] < s[i]){
            increaseIdx = i;
            break;
        }
    }
    
    if(increaseIdx == -1){
        reverse(s.begin(), s.end());
        return stoi(s);
    }else{
        int l = increaseIdx-1;
        int r = s.length()-1;
        
        while(s[l] >= s[r]) r--;
        swap(s[l], s[r]);
        
        int maxIdx = l+1;
        int minIdx = s.length()-1;
        
        while(maxIdx < minIdx){
            swap(s[maxIdx], s[minIdx]);
            maxIdx++;
            minIdx--;
        }
        return stoi(s);
    }
}