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
    int solve(TreeNode* node, int & maxSum){
        if(node==nullptr) return 0;

        int left = solve(node->left,maxSum);
        int right = solve(node->right,maxSum);

        
        int currSum=node->val;
        if(left>0) currSum+=left;
        if(right>0) currSum+=right;

        maxSum=max(currSum,maxSum);


        int returnVal=node->val+max(0,max(left,right));
        return returnVal;

    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;

        solve(root,maxSum);

        return maxSum;
    }
};