vector<int> getPi(string s){
    int m = s.size();

    // pi는 0부터 시작하기에 항상 -1을 해주어 접근
    vector<int> pi(m);

    int begin = 1, matched = 0;

    while(begin + matched < m){
        // 매치 됐을 경우 값 최신화
        if(s[begin+matched] == s[matched]){
            ++matched;
            pi[begin+matched-1] = matched;
        }
            // 매치 안될 경우
        else{
            if(matched == 0)
                ++begin;
                // 이전 값 이용해 다음 위치 계산
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}


bool kmp(string pattern, string str, vector<int> pis) {
    int matched = 0, begin = 0;
    int m = str.size();
    int n = pattern.size();
    while (begin <= (m - n)) {
        if (matched < pattern.size() && str[begin + matched] == pattern[matched]) {
            ++matched;
            if (matched == pattern.size()){
                return true;
            }
        } else {
            if (matched == 0)
                ++begin;
            else if (matched - 1 < pis.size()) {
                begin += matched - pis[matched - 1];
                matched = pis[matched - 1];
            }
        }
    }
    return false;
}