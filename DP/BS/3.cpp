// Regular Expression Matching
bool find(string& pattern, string s, int pi, int si){
    if(pi == pattern.length())
        return si == s.length();
    
    bool isMatched = si < s.length() && (pattern[pi] == s[si] || pattern[pi] == '.');
    
    // run func before *(Kleene) operator
    if(pi+1 < pattern.length() && pattern[pi+1] == '*'){
        return find(pattern, s, pi+2, si) || (isMatched && find(pattern, s, pi, si+1));
    }
    
    if(isMatched)
        return find(pattern, s, pi+1, si+1);
    else
        return false;
}


bool solve(string pattern, string s) {
    return find(pattern, s, 0, 0);
}