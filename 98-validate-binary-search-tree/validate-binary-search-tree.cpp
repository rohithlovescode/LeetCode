class Solution {
public:
    bool dfs(TreeNode* root,long mini,long maxi){
        if(root==NULL) return true;
        if(root->val<=mini||root->val>=maxi) return false;

        return dfs(root->left,mini,root->val)&&dfs(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MIN,LONG_MAX);
    }
};