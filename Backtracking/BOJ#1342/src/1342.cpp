#include <bits/stdc++.h>
#include <stdio.h>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
const int MAX = 987654321;
const int MIN = -987654321;
bool indexCheck(int r, int c, int rowSize, int colSize){
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}
const char endL = '\n';

using namespace std;

struct State{
    char ch = ' ';
    int cnt;
};
vector<State> chars;
string str;
int ans;

bool check(vector<char>& visitList){
    for (int i = 1; i < visitList.size(); ++i) {
        if(visitList[i] == visitList[i-1])
            return false;
    }
    return true;
}


void dfs(int cnt, vector<char>& visitList){
    if(cnt == str.length()){
        if(check(visitList)){
            ans++;
            return;
        }
    }

    for (int i = 0; i < chars.size(); i++) {
        if(chars[i].cnt > 0){
            visitList.push_back(chars[i].ch);
            chars[i].cnt--;
            dfs(cnt+1, visitList);
            chars[i].cnt++;
            visitList.pop_back();
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    cin >> str;

    map<char, int> m;
    for (int i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if(!m[ch]){
            m[ch] = 1;
        }else{
            m[ch] += 1;
        }
    }

    for(auto it = m.begin(); it != m.end(); it++){
        chars.push_back({it->first, it->second});
    }

    vector<char> visitList;
    dfs(0, visitList);

    cout << ans;


    return 0;
}


