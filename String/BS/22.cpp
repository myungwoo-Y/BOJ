// Add Binary Numbers

string solve(string a, string b) {
    string ret = "";
    
    int len = a.length() > b.length() ? a.length() : b.length();
    
    int add = 0;
    for (int i = 0; i < len; i++) {
        int valueA = a.length()-1 >= i ? (a[a.length()-i-1] - '0') : 0;
        int valueB = b.length()-1 >= i ? (b[b.length()-i-1] - '0') : 0;
        
        int sum = valueA + valueB + add;
        ret.push_back(sum % 2 + '0');
        add = sum > 1;
    }
    
    if(add) ret.push_back(1 + '0');
    reverse(ret.begin(), ret.end());
    return ret;
    
}