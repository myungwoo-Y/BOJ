// Title : Binary Tree Maximum Path Sum

struct Node{
    // first : max value between left and right
    // second : sum child, valid when the node is represented as root
    pair<int, int> sum;
    
    // representing the idx of node
    int n;
    
    Node() : sum({INT32_MIN, INT32_MIN}), n(-1)
    {
    }
};
  
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    void fillPath(TreeNode* root, vector<Node>& nodes, int& n){
        
        int cur = n;
        nodes[cur].n = n;
    
        
        // leaf node
        if(root->left == nullptr && root->right == nullptr){
            nodes[cur].sum.first = root->val;
            nodes[cur].sum.second = root->val;
            
        // right node only
        }else if(root->left == nullptr){
            int rightChild = n+1;
            
            fillPath(root->right, nodes, ++n);
            
            int rightVal = nodes[rightChild].sum.first;
            nodes[cur].sum.first = root->val;
            if(rightVal > 0)
                nodes[cur].sum.first = root->val + rightVal;
            nodes[cur].sum.second = nodes[cur].sum.first;
            
        // left node only
        }else if(root->right == nullptr){
            int leftChild = n+1;
            
            fillPath(root->left, nodes, ++n);
                
            int leftVal = nodes[leftChild].sum.first;

            nodes[cur].sum.first = root->val;
            if(leftVal > 0)
                nodes[cur].sum.first = root->val + leftVal;
            nodes[cur].sum.second = nodes[cur].sum.first;
            
        
        // have a both of node
        }else{
            int leftChild = n+1;
            fillPath(root->left, nodes, ++n);
            
            int rightChild = n+1;
            fillPath(root->right, nodes, ++n);
            
            Node* leftNode = &nodes[leftChild];
            Node* rightNode = &nodes[rightChild];
            
            nodes[cur].sum.first = root->val;
            nodes[cur].sum.second = root->val;
            nodes[cur].sum.first = root->val + max({0, leftNode->sum.first, rightNode->sum.first});
            if(leftNode->sum.first > 0 && rightNode->sum.first > 0){
                nodes[cur].sum.second = root->val + leftNode->sum.first + rightNode->sum.first;
            }else if(leftNode->sum.first > 0){
                nodes[cur].sum.second = root->val + leftNode->sum.first;
            }else if(rightNode->sum.first > 0){
                nodes[cur].sum.second = root->val + rightNode->sum.first;
            }
        }
    }
    
    
    int maxPathSum(TreeNode* root) {
        int m = INT32_MIN, n = 0;
        
        vector<Node> nodes(30001);
        
        fillPath(root, nodes, n);
        
        
        for(auto& node : nodes){
            m = max(m, node.sum.second);
        }
        
        
        return m;
    }
};