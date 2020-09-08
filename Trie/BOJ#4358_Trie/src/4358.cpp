#include <bits/stdc++.h>
#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#define MAX 987654321
#define MIN -987654321
#include <ctype.h>
using namespace std;
const char endL {'\n'};
int new_id {};
int total;
const int ALPHABETS = '~' - ' ' + 1;
int charToNum(char ch){
    return ch - ' ';
}
char numberToChar(int n){
    return ' ' + n;
}
const int NOT_DEFINE {-1};
int cache[2000001];
struct TrieNode{
    TrieNode* child[ALPHABETS];
    bool isTerminal;
    int id {NOT_DEFINE};
    TrieNode() : isTerminal(false){
        memset(child, 0, sizeof(child));
    }
    ~TrieNode(){
        for (int i = 0; i < ALPHABETS; ++i) {
            if(child[i])
                delete child[i];
        }
    }

    void preOrder(string str){
        if(isTerminal){
            cout << str + " " << ((double)cache[id] / total) * 100 << endL;
        }
        for (int i = 0; i < ALPHABETS; ++i) {
            if(child[i]){
                char newCh = numberToChar(i);
                child[i]->preOrder(str+newCh);
            }
        }
        return;
    }
    void insert(const char* key){
        if(*key == 0){
            isTerminal = true;
            if(id == NOT_DEFINE)
                id = new_id++;
            cache[id]++;
            total++;
        }else {
            int next = toNumber(*key);
            if(next >= ALPHABETS || next < 0)
                return;
            if(child[next] == NULL)
                child[next] = new TrieNode;
            child[next]->insert(key+1);
        }
    }
    TrieNode* find(const char* key){
        if(*key==0)
            return this;
        int next = toNumber(*key);
        if(child[next] == NULL)
            return NULL;
        return child[next]->find(key+1);
    }
};

map<string, double> m;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    string str;
    TrieNode* tri = new TrieNode();
    while(getline(cin, str)){
        tri->insert(str.c_str());
    }
    cout.setf(ios::fixed);
    cout.precision(4);
    tri->preOrder("");
    for(auto a : m){
        cout << a.first << " " << (a.second/total)*100 << endL;
    }
    return 0;
}