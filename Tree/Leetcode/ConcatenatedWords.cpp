// 472. Concatenated Words

class TrieNode {
public: 
    char value;
    unordered_map<char, TrieNode*> child;
    bool isEnd;
    
    TrieNode(char _value) {
        value = _value;
        child = unordered_map<char, TrieNode*>();
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* head;
    
    Trie() {
        head = new TrieNode(' ');
    }

    void addWord(string str) {
        auto node = head;
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if (node->child.find(c) == node->child.end()) {
                node->child[c] = new TrieNode(c);
            }
            node = node->child[c];
        }
        node->isEnd = true;
    }

    bool isConcatenatedWord(string str, bool isFirst) {
        auto node = head;
        for (int i = 0; i < str.size()-1; i++) {
            char c = str[i];
            
            if (node->child.find(c) != node->child.end()) {
                node = node->child[c];
                if (node->isEnd) {
                    bool ret = isConcatenatedWord(str.substr(i+1, str.size()-i-1), false);
                    if (ret) {
                        return ret;
                    }    
                }
            } else {
                return false;
            }
        }
        
        if (node->child.find(str.back()) != node->child.end()) {
            node = node->child[str.back()];
        } else {
            return false;
        }
        
        if (isFirst) {
            return false;
        } else {
            return node->isEnd;
        }
    }
};


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie trie;
        vector<string> ret;

        for (auto& word: words) {
            trie.addWord(word);
        }

        for (auto& word: words) {
            if (trie.isConcatenatedWord(word, true)) {
                ret.push_back(word);
            }
        }

        return ret;
    }
};