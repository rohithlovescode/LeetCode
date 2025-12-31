
class Solution {
public:
    int dfs(TreeNode* root,int& ans){
        if(!root) return 0;
        int left=dfs(root->left,ans);
        int right=dfs(root->right,ans);
        
        left=left>0?left:0;
        right=right>0?right:0;
        ans=max(ans,root->val+left+right);
        
        return max(left,right)+root->val;
        
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
    }
};