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
    int ans;
public:
    int solve(TreeNode* node){
        if(!node) return 0;

        int left=solve(node->left);
        int right=solve(node->right);

        int tempAns=node->val+left+right;
        ans=max(ans,tempAns);

        int retVal=node->val+max(left,right);
        return retVal>0? retVal:0;
    }
    int maxPathSum(TreeNode* root) {
        ans=root->val;
        solve(root);

        return ans;
        
    }
};