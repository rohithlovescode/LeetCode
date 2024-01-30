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
    bool balanced=true;
    void isBalancedVoid(TreeNode* root) {
        
        if(root==NULL){
            return;
        }
        int left=height(root->left);
        int right=height(root->right);
        if(abs(left-right)>1){
            balanced=false;
        }
        if(balanced==false){
            return;
        }
        isBalanced(root->left);
        isBalanced(root->right);
        
    }
    bool isBalanced(TreeNode* root) {
        isBalancedVoid(root); return balanced;
    }
};