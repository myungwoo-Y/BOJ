// 208. Implement Trie (Prefix Tree)
class TrieNode {
public:
    TrieNode* child[26];
    bool isWord = false;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* pt = root;
        for (char ch : word) {
            int childIdx = ch - 'a';
            if (pt->child[childIdx] == nullptr) {
                pt->child[childIdx] = new TrieNode();
            }
            pt = pt->child[childIdx];
        }
        pt->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* pt = root;
        for (char ch : word) {
            int childIdx = ch - 'a';
            if (pt->child[childIdx] == nullptr) {
                return false;
            }
            pt = pt->child[childIdx];
        }
        return pt->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* pt = root;
        for (char ch : prefix) {
            int childIdx = ch - 'a';
            if (pt->child[childIdx] == nullptr) {
                return false;
            }
            pt = pt->child[childIdx];
        }
        return true;
    }
};