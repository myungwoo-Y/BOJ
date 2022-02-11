// 212. Word Search II
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
    
};

class Solution {
public:
    Trie trie;
    bool visited[12][12];
    unordered_set<string> s;
    vector<vector<int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    
    void findWord(int i, int j, string preWord, TrieNode* node, vector<vector<char>>& board) {
        char ch = board[i][j];
        
        if (node == nullptr || node->child[ch - 'a'] == nullptr) return;
        
        TrieNode* nextNode = node->child[ch - 'a'];
        preWord += string(1, ch);
        
        if (nextNode->isWord) s.insert(preWord);
        
        for (int dir = 0; dir < 4; dir++) {
            int newR = i + dirs[dir][0];
            int newC = j + dirs[dir][1];
            
            if (newR < 0 || newR >= board.size() || newC < 0 || newC >= board[0].size() || visited[newR][newC]) continue;
            visited[newR][newC] = true;
            findWord(newR, newC, preWord, nextNode, board);
            visited[newR][newC] = false;
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // init Trie
        for (string word : words) {
            trie.insert(word);
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                visited[i][j] = true;
                findWord(i, j, "", trie.root, board);
                visited[i][j] = false;
            }
        }
        
        return vector<string>(s.begin(), s.end());
    }
};