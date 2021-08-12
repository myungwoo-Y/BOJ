string solve(string s) {
    
    stack<char> st;
    
    for (int i = 0; i < s.length(); i++) {
        char cur = s[i];
        
        if(!st.empty() && cur == st.top()){
            while(i < s.length() && s[i] == st.top()) ++i;
            st.pop();
            --i;
        }else{
            st.push(cur);
        }
    }
    
    string ret = "";
    
    while (!st.empty()) {
        ret = string(1, st.top()) + ret;
        st.pop();
    }
    
    return ret;
}