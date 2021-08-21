// Left Side View of a Tree
class Tree {
  public:
     int val;
     Tree *left;
     Tree *right;
 };

void search(Tree* root, int order, vector<int>& elements){
    if(root == nullptr) return;
    
    if(elements.size() == order)
        elements.push_back(root->val);
    
    search(root->left, order+1, elements);
    search(root->right, order+1, elements);
}

 
vector<int> solve(Tree* root) {
    vector<int> elements;
    
    search(root, 0, elements);
    
    return elements;
}