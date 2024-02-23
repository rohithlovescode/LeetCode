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
    TreeNode* flattenTree(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        if(root->left){
            TreeNode* left=flattenTree(root->left);
            TreeNode* temp=left;
            while(temp->right){
                temp=temp->right;
            }
            temp->right=flattenTree(root->right);
            root->left=NULL;
            root->right=left;
        }else{
            root->right=flattenTree(root->right);
        }
        return root;
    }
public:
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};