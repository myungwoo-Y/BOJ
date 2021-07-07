// Level Order Binary Tree to Linked List

class Tree {
  public:
      int val;
      Tree *left;
      Tree *right;
};

class LLNode {
  public:
      int val;
      LLNode *next;
};
 
LLNode* solve(Tree* root) {
    queue<Tree*> q;
    LLNode* ret = nullptr;
    LLNode* cur = nullptr;
    
    q.push(root);
    
    while(!q.empty()){
        Tree* node = q.front();
        q.pop();
        
        LLNode* newNode = new LLNode({node->val, nullptr});
        
        if(ret == nullptr){
            ret = cur = newNode;
        }else{
            cur->next = newNode;
            cur = cur->next;
        }
        
        
        if(node->left != nullptr) q.push(node->left);
        
        if(node->right != nullptr) q.push(node->right);
    }
    
    return ret;
}