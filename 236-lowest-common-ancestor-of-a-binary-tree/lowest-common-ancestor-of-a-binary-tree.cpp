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
    bool recurse(TreeNode*& root,TreeNode*& p,TreeNode*& q,TreeNode* &ans){
        if(root==NULL||ans!=NULL){
            return false;
        }
        if(root==p&&root==q){
            ans=root;
            return true;
        }
        bool left=recurse(root->left,p,q,ans);
        bool right=recurse(root->right,p,q,ans);
        bool curr=(root==p)||(root==q);
        if((left&&right)||(left&&curr)||(right&&curr)){
            ans=root;
        }
        return curr||left||right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        recurse(root,p,q,ans);

        return ans;

    }
};