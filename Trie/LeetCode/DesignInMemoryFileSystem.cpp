// 588. Design In-Memory File System

const int numberOfChar = 26;

class TrieNode {
public:
    unordered_map<string, TrieNode*> childs;
    bool isFile = false;
    string content, name;
    
    TrieNode(string path) {
        name = path;
    }
    
    TrieNode() {}
    
};

struct Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    TrieNode* moveToTarget(string path) {
        if (path == "/") return root;
        TrieNode* pt = root;
        vector<string> paths = split(path);
        
        for (string subPath : paths) {
            if (pt->childs[subPath] == nullptr) {
                pt->childs[subPath] = new TrieNode(subPath);
            }
            pt = pt->childs[subPath];
        }
        
        return pt;
    }
    
    void addContent(string path, string content) {
        TrieNode* pt = moveToTarget(path);
    
        if (pt->isFile) {
            pt->content += content;
        } else {
            pt->isFile = true;
            pt->content = content;
        }
    }
    
    vector<string> getSibling(string path) {
        TrieNode* pt = moveToTarget(path);
        vector<string> ret;
        
        if (pt->isFile) {
            ret.push_back(pt->name);
        } else {
            for (auto child : pt->childs) {
                if (child.second != nullptr) {
                    ret.push_back(child.first);
                }
            }
        }
        
        sort(ret.begin(), ret.end());
        
        return ret;
    }
    
    string getTargetContent(string path) {
        TrieNode* pt = moveToTarget(path);
        return pt->content;
    }
    
    
private:
    vector<string> split(const string& input) {
        std::regex re("/");
        sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;
        first++;
        return {first, last};
    }
    

};


class FileSystem {
public:
    Trie trie;
    FileSystem() {}

    vector<string> ls(string path) {
        return trie.getSibling(path);
    }

    void mkdir(string path) {
        trie.moveToTarget(path);
    }

    void addContentToFile(string filePath, string content) {
        trie.addContent(filePath, content);
    }

    string readContentFromFile(string filePath) {
        return trie.getTargetContent(filePath);
    }
};