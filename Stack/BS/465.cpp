void getElement(int& a, int& b, stack<string>& st, vector<string> syntaxs, int i){
    bool isNextMinus = syntaxs[i+1] == "-";
    b = isNextMinus ? -1 * (stoi(syntaxs[i+2])) : stoi(syntaxs[i+1]);
    if(st.top() == "-"){
        st.pop();
        a = -1 * stoi(st.top());
        st.pop();
    }else{
        a = stoi(st.top());
        st.pop();
    }
}

int solve(string s) {
    
    vector<string> syntaxs;
    
    // preprocess syntaxs
    string syntax = "";
    for(int i = 0; i < s.length(); i++){
        
        // check whether minus num is first element
        if(i == 0 && s[0] == '-'){
            syntax += "-";
            continue;
        }

        char ch = s[i];
        
        if(ch == '/' || ch == '*' || ch == '-' || ch == '+'){
            if(ch == '-'){
                if(syntaxs.size() > 0 && syntax == "" && (syntaxs.back() == "*" || syntaxs.back() == "/")){
                    syntax += "-";
                    continue;
                }
            }
            syntaxs.push_back(syntax);
            syntaxs.push_back(string(1, ch));
            syntax = "";
        }else{
            syntax += string(1, ch);
        }
        
    }
    
    if(syntax != "") syntaxs.push_back(syntax);
    
    stack<string> st;

    for(int i = 0; i < syntaxs.size(); i++){
        string syntax = syntaxs[i];
        int b = 0;
        int a = 0;
        bool isNextMinus = i+1 < syntaxs.size() ? syntaxs[i+1] == "-" : false;
        if(syntax == "/"){
            getElement(a, b, st, syntaxs, i);
            st.push(to_string(floor(a*1.0 / b)));
            i += isNextMinus + 1;
        }else if(syntax == "*"){
            getElement(a, b, st, syntaxs, i);
            st.push(to_string(a * b));
            i += isNextMinus + 1;
        }else{
            st.push(syntax);
        }
    }
    
    stack<string> reverseSt;
    // reverse origin stack to arrange normal sequence
    while(!st.empty()){
        string syntax = st.top();
        st.pop();
        reverseSt.push(syntax);
    
    }
    
    
    while(reverseSt.size() > 1){
        int a = stoi(reverseSt.top());
        reverseSt.pop();
        string op = reverseSt.top();
        reverseSt.pop();
        int b = stoi(reverseSt.top());
        reverseSt.pop();
        
        if(op == "-"){
            reverseSt.push(to_string(a - b));
        }else{
            reverseSt.push(to_string(a + b));
        }
    }

    return stoi(reverseSt.top());
    
}