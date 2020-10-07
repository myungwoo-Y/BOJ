#include <bits/stdc++.h>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#define MAX 987654321
#define MIN -987654321
#include <ctype.h>

const char endL {'\n'};
using namespace std;

const int ALPHABETS = 26;
int charToNum(char ch){
    return ch - 'a';
}

struct TrieNode{
    TrieNode* child[ALPHABETS];
    bool isEnd {};
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
            if(!child[next])
                child[next] = new TrieNode();
            child[next]->insert(key+1);
        }
    }
    TrieNode* find(const char* key){
        if(*key==0)
            return this;
        int next = charToNum(*key);
        if(!child[next])
            return nullptr;
        return child[next]->find(key+1);
    }
};


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif


    return 0;
}