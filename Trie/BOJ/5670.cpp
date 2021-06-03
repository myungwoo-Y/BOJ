#include <bits/stdc++.h>
#include <queue>
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
const char newline = '\n';

using namespace std;

int programsN, k, ans;
bool isFirst;
vector<vector<int>> programs;

const int ALPHABETS = 26;
int charToNum(char ch){
    return ch - 'a';
}

struct TrieNode{
    TrieNode* child[ALPHABETS];
    bool isEnd {};
    int childCount = 0;
    TrieNode():isEnd(false){
        memset(child, 0, sizeof(child));
    }
    ~TrieNode(){
        for(auto node : child)
            if(node)
                delete node;
    }
    void insert(const char* key){
        if(*key == 0)
            isEnd = true;
        else{
            int next = charToNum(*key);
            if(!child[next]){
                child[next] = new TrieNode();
                childCount++;
            }
            child[next]->insert(key+1);
        }
    }
    TrieNode* find(const char* key){
        if(*key==0)
            return this;
        if(isFirst){
            ans++;
            isFirst = false;
        }else if(isEnd || childCount > 1){
            ans++;
        }
        int next = charToNum(*key);
        if(!child[next])
            return nullptr;
        return child[next]->find(key+1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    string a {};

    cout << fixed;
    cout.precision(2);
    int n = 0;
    while(cin >> n){
        vector<string> words;
        auto trieNode = new TrieNode();
        words.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
            trieNode->insert(words[i].c_str());
        }
        ans = 0;
        for (int i = 0; i < n; ++i) {
            isFirst = true;
            trieNode->find(words[i].c_str());

        }
        double result = ans/(double)n;
        cout << round(result * 100) / 100 << newline;
        delete trieNode;
    }

    return 0;
}


