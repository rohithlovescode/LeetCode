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
    int recurse(TreeNode* root,int& maxSum){
        if(root==NULL){
            return 0;
        }
        int left=recurse(root->left,maxSum);
        int right=recurse(root->right,maxSum);

        int curr=root->val+max(0,left)+max(0,right);
        maxSum=max(curr,maxSum);
        return root->val+max(0,max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        recurse(root,maxSum);

        return maxSum;
    }
};