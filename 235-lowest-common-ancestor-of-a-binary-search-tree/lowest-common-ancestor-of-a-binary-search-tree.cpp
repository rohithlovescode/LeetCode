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
    bool solve(TreeNode* curr, TreeNode* p, TreeNode* q, TreeNode* &lca){
        if(!curr) return false;

        bool left=solve(curr->left, p,q,lca);
        bool right=solve(curr->right,p,q,lca);

        if(lca) return true;

        if(left&&right ||( (curr==p||curr==q)&&(left||right))) lca=curr;


        return left||right||p==curr||q==curr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca=nullptr;
        solve(root,p,q,lca);

        return lca;
    }
};