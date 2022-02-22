 // 297. Serialize and Deserialize Binary Tree

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "[]";
        
        queue<TreeNode*> q;
        vector<string> nodes;
        string ret = "";

        nodes.push_back(to_string(root->val));

        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            auto* node = q.front();
            q.pop();

            if (node == nullptr) {
                nodes.push_back("null");
            } else {
                nodes.push_back(to_string(node->val));
                if (node->left == nullptr) {
                    q.push(nullptr);
                } else {
                    q.push(node->left);
                }

                if (node->right == nullptr) {
                    q.push(nullptr);
                } else {
                    q.push(node->right);
                }
            }
        }

        ret += "[";

        // remove empty node
        while (!nodes.empty() && nodes.back() == "null") {
            nodes.pop_back();
        }

        for (string node : nodes) {
            ret += node + ",";
        }

        if (ret.length() > 2) {
            ret = ret.substr(0, ret.length()-1);
        }

        ret += "]";

        return ret;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() <= 2) return nullptr;
        vector<string> nodes = parsingNode(data);
        
        queue<TreeNode*> q;

        int nodeIdx = 0;

        TreeNode* root = new TreeNode(stoi(nodes[nodeIdx++]));

        q.push(root);

        while (!q.empty()) {
            
            TreeNode* node = q.front();
            q.pop();

            if (nodeIdx >= nodes.size()) break;

            if (nodes[nodeIdx] != "null") {
                node->left = new TreeNode(stoi(nodes[nodeIdx]));
                q.push(node->left);
            } 
            nodeIdx++;

            if (nodeIdx >= nodes.size()) break;

            if (nodes[nodeIdx] != "null") {
                node->right = new TreeNode(stoi(nodes[nodeIdx]));
                q.push(node->right);
            } 
            nodeIdx++;
        }
        return root;
    }

    vector<string> parsingNode(string _data) {
        string data = _data.substr(1, _data.length()-2);
        std::regex re(",");
        sregex_token_iterator first{data.begin(), data.end(), re, -1}, last;
        return {first, last};
    }
};