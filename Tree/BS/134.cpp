/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int search(Tree* root, int lo, int hi){
    int ret = 0;
    
    if(root == nullptr) return ret;
    
    if(lo <= root->val && root->val <= hi){
        ret++;
    }
    if(root->left != nullptr) ret += search(root->left, lo, hi);
    if(root->right != nullptr) ret += search(root->right, lo, hi);
        
    return ret;
}


int solve(Tree* root, int lo, int hi) {
    return search(root, lo, hi);
}
