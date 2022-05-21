// 1948. Delete Duplicate Folders in System

class TrieNode {
public:
    map<string, TrieNode*> child;
    string val;
    bool isMarked;
    
    TrieNode(string _val = "") {
        val = _val;
        isMarked = false;
    }
};


class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, TrieNode*> seen;
    void addPath(vector<string>& path, TrieNode* node) {
        TrieNode* cur = node;
        for (auto& v : path) {
            if (cur->child.find(v) == cur->child.end()) {
                cur->child[v] = new TrieNode(v);
            }
            cur = cur->child[v];
        }
    }
    
    string checkMark(TrieNode* node) {
        string subfolder;
        
        for (auto& [val, child] : node->child) {
            subfolder += checkMark(child);
        }
        
        if (subfolder.size()) {
            if (seen.find(subfolder) == seen.end()) {
                seen[subfolder] = node;
            } else {
                seen[subfolder]->isMarked = node->isMarked = true;
            }
        }
        
        return "[" + node->val + subfolder + "]";
    }
    
    void findAns(TrieNode* node, vector<string>& parents) {
        if (node->isMarked) return;
        parents.push_back(node->val);
        ans.push_back(parents);
        for (auto& [val, child] : node->child) {
            findAns(child, parents);
        }
        parents.pop_back();
    }
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
       TrieNode head;
        
        for (auto& path : paths) {
            addPath(path, &head);
        }
    
        checkMark(&head);
        
        for (auto& [val, child] : head.child) {
            vector<string> parents;
            findAns(child, parents);
        }
            
        return ans;
    }
};

















