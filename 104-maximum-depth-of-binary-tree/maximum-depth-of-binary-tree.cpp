class Solution {
    int height=0;
    void maxHeight(TreeNode* root,int depth){
        if(root==nullptr){
            return;
        }
        if(height<depth){
            height=depth;
        }
        maxHeight(root->left,depth+1);
        maxHeight(root->right,depth+1);

    }
public:
    int maxDepth(TreeNode* root) {
        maxHeight(root,1);
        return height;
    }
};