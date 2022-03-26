// 642. Design Search Autocomplete System

class TrieNode {
public:
    unordered_map<char, TrieNode*> child;
    vector<pair<string, int>> words;
};

class Trie {
public:
    TrieNode* head;
    TrieNode* searchLevel;
    string inputWord;
    vector<TrieNode*> levels;

    Trie() {
        head = new TrieNode();
        searchLevel = nullptr;
        inputWord = "";
    }

    void insert(string word, int time) {
        TrieNode* curLevel = head;
        for (int i = 0; i < word.length(); i++) {
            if (curLevel->child.find(word[i]) == curLevel->child.end()) {
                curLevel->child[word[i]] = new TrieNode();
            }
            curLevel = curLevel->child[word[i]];
            
            updateWords(curLevel->words, word, time);
        }
    }

    void updateWords(vector<pair<string, int>>& words, string& word, int time) {
        bool isContain = false;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].first == word) {
                words[i].second = time;
                isContain = true;
            }
        }
        if (!isContain) {
            words.push_back({word, time});
        }
        sort(words.begin(), words.end(), [](auto& a, auto& b) -> bool {
            if (a.second == b.second) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        });
        if (words.size() > 3) {
            words.pop_back();
        }
    }    

    vector<string> findHotDegree(char c, unordered_map<string, int>& m) {
        vector<string> ret;

        if (c == '#') {
            int time = 1;
            if (m.find(inputWord) != m.end()) {
                time = m[inputWord] + 1;
            }
            for (auto& level : levels) {
                updateWords(level->words, inputWord, time);
            } 
            m[inputWord] = time;
            searchLevel = nullptr;
            inputWord = "";
            levels = vector<TrieNode*>();
            return ret;
        }

        if (searchLevel == nullptr) {
            searchLevel = head;
        }

        inputWord += string(1, c);

        if (searchLevel->child.find(c) == searchLevel->child.end()) {
            searchLevel->child[c] = new TrieNode();
        }
        searchLevel = searchLevel->child[c];
        levels.push_back(searchLevel);
        for (auto& word : searchLevel->words) {
            ret.push_back(word.first);
        }
        return ret;
    }    
};



class AutocompleteSystem {
public:
    unordered_map<string, int> m;
    Trie trie;

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        // build trie
        for (int i = 0; i < sentences.size(); i++) {
            string& sentence = sentences[i];
            m[sentence] = times[i];

            trie.insert(sentence, times[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> ret;

        return trie.findHotDegree(c, m);
    }
};