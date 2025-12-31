/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool recurse(TreeNode* root, TreeNode*p, TreeNode* q, TreeNode* &ans){
        if(root==nullptr) return false;
        bool left=recurse(root->left, p,q,ans);
        bool right=recurse(root->right,p,q,ans);

        if((root==p||root==q)&&(left||right)){
            cout<<root->val;

            ans= root;
        }
        else if(left&&right){
            cout<<root->val;
            ans=root;
        }

        return root==p||root==q||left||right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=nullptr;
        recurse(root,p,q,ans);
        return ans;
    }
};