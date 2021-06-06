// Univalue Tree Count
class Tree {
  public:
    Tree(int initVal){
        val = initVal;
        left = nullptr;
        right = nullptr;
    }
    Tree(){}
    int val;
    Tree *left;
    Tree *right;
};

int ans = 0;
 
bool findUniTree(Tree* tree){
    bool status = true;
    
    if(tree->left){
        status &= findUniTree(tree->left) && tree->left->val == tree->val;
    }
    
    if(tree->right){
        status &= findUniTree(tree->right) && tree->right->val == tree->val;
    }
    
    if(status){
        ans++;
        return true;
    }else{
        return false;
    }
}


int solve(Tree* root) {
    findUniTree(root);
    int ret = ans;
    ans = 0;
    return ret;
}