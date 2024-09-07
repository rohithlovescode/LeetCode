
class Solution {

    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);

        int val= max(left,right)+1;

        return val;
    }

public:
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL){
            return true;
        }
        int left=height(root->left);
        int right=height(root->right);
        if(abs(left-right)>1){
            return false;
        }
        
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};