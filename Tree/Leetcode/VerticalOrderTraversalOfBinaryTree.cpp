// 987. Vertical Order Traversal of a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Node {
public: 
    int row, col, val;
    
    Node(int _row, int _col, int _val) {
        row = _row;
        col = _col;
        val = _val;
    }
    
    Node(){}
};

struct cmp {
  bool operator()(Node& a, Node& b) {
      if (a.col != b.col) {
          return a.col > b.col;
      } else if (a.row != b.row) {
          return a.row > b.row;
      } else {
          return a.val > b.val;
      }
  }  
};

class Solution {
public:
    priority_queue<Node, vector<Node>, cmp> q;
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ret;
        
        searchAndInsert(root, 0, 0);
        Node prev;
        
        while (!q.empty()) {
            Node cur = q.top();
            q.pop();
            if (ret.size() == 0 || prev.col != cur.col) {
                ret.push_back({});
            }
            
            ret.back().push_back(cur.val);
            
            prev = cur;
        }
        
        return ret;
    }
    
    void searchAndInsert(TreeNode* root, int row, int col) {
        if (root == nullptr) return;
        
        q.push({row, col, root->val});
        searchAndInsert(root->left, row+1, col-1);
        searchAndInsert(root->right, row+1, col+1);
    }
};