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
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(height(root->left),height(root-> right)) +1;
    }
    void recurse(TreeNode* root,int level,vector<int> &sol){
        if(root==NULL){
            return;
        }
        sol[level]=root->val;

        recurse(root->left,level+1,sol);
        recurse(root->right,level+1,sol);
    }
    vector<int> rightSideView(TreeNode* root) {
        int treeSize=height(root);
        vector<int> sol(treeSize,0);
        int level=0;
        recurse(root,level,sol);
        return sol;
    }
};