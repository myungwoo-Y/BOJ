// 301. Remove Invalid Parentheses
class Solution {
public:
    queue<string> q;
    unordered_set<string> letters;
    
    bool isValidParen(string& paren) {
        stack<char> st;
        
        string pureStr = "";
        
        for (char& ch : paren) {
            if (ch == '(' || ch == ')') {
                pureStr += string(1, ch);
            }
        }
        
        for (char& c : pureStr) {
            if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        
        return st.empty();
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        
        if (isValidParen(s)) {
            return { s }; 
        }
        
        for (int i = 0; i < s.size(); i++) {
            string nextStr = s.substr(0, i) + s.substr(i+1, s.length()-i-1);
            if (letters.find(nextStr) == letters.end()) {
                q.push(nextStr);
                letters.insert(nextStr);                
            }
        }
        
        while (!q.empty() && !ans.size()) {
            int queueSize = q.size();
            for (int i = 0; i < queueSize; i++) {
                string preStr = q.front();
                q.pop();
                
                if (isValidParen(preStr)) {
                    ans.push_back(preStr);
                }
                
                for (int i = 0; i < preStr.size(); i++) {
                    string nextStr = preStr.substr(0, i) + preStr.substr(i+1, preStr.length()-i-1);
                    if (letters.find(nextStr) == letters.end()) {
                        q.push(nextStr);
                        letters.insert(nextStr);
                    }
                }
            }
        }
        
        return ans;
    }
};