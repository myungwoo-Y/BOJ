#include <bits/stdc++.h>

#define SI string::iterator
#define LL long long int
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
bool indexCheck(int r, int c, int rowSize, int colSize){
    return !(r < 0 || r >= rowSize || c < 0 || c >= colSize);
}

using namespace std;

const char endL {'\n'};

// white space 고려
const int ALPHABETS = 26+1;
const int EndIdx = 26;
int charToNum(char ch){
    if(ch == ' ')
        return EndIdx;
    else
        return ch - 'A';
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

    void printMap(string prefix, bool isPrefix){
        if(isEnd)
            cout << endL;
        for (int i = 0; i < ALPHABETS; ++i) {
            if(child[i]){
                if(i == ALPHABETS-1){
                    cout << endL;
                    string newPrefix = prefix+"--";
                    child[i]->printMap(newPrefix, true);
                }else{
                    string addedPrefix = isPrefix ? prefix : "";
                    cout << addedPrefix + string(1, 'A'+i);
                    child[i]->printMap(prefix, false);
                }
            }
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int inputSize {};
    cin >> inputSize;
    cin.ignore();
    TrieNode* trieNode = new TrieNode();
    loop(inputSize){
        string str;
        getline(cin, str);
        string info = str.substr(str.find(" ")+1, str.length()-1);
        trieNode->insert(info.c_str());
    }
    trieNode->printMap("", false);
    return 0;
}