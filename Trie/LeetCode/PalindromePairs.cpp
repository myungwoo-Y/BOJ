// 336. Palindrome Pairs

class TrieNode {
public:
    unordered_map<char, TrieNode*> child;
    vector<int> palins;
    bool isWord = false;
    int idx = -1;
};

class Trie {
public:
    TrieNode* head = new TrieNode();

    void insert(string& s, int wordId) {
        TrieNode* node = head;
        for (int i = 0; i < s.length(); i++) {
            if (isPalin(s, i, s.length()-1)) {
                node->palins.push_back(wordId);
            }
            if (node->child.find(s[i]) == node->child.end()) {
                node->child[s[i]] = new TrieNode();
            }
            node = node->child[s[i]];
        }
        node->isWord = true;
        node->idx = wordId;
    }

    void searchPalin(string& s, int wordId, vector<vector<int>>& ret) {
        TrieNode* node = head;
        for (int i = 0; i < s.length(); i++) {
            if (node->isWord && wordId != node->idx && isPalin(s, i, s.length()-1)) {
                ret.push_back({wordId, node->idx});
            }
            if (node->child.find(s[i]) == node->child.end()) {
                return;
            }
            node = node->child[s[i]];
        }
        
        if (node == nullptr) return;
        
        for (int palinIdx : node->palins) {
            ret.push_back({wordId, palinIdx});
        }
        if (node->isWord && wordId != node->idx) {
            ret.push_back({wordId, node->idx});
        }
    }

    bool isPalin(string& s, int start, int end) {
        if (start > end) return false;
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;

        Trie trie;
        
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            reverse(s.begin(), s.end());
            trie.insert(s, i);
        }

        for (int i = 0; i < words.size(); i++) {
            trie.searchPalin(words[i], i, ret);
        }

        return ret;
    }
};