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
    bool isValid(TreeNode* root, long lBound, long rBound){
        if(!root) return true;

        int val = root->val;

        if(val<=lBound||val>=rBound) return false;

        return isValid(root->left,lBound,root->val)&&isValid(root->right,root->val, rBound);
    }
    bool isValidBST(TreeNode* root) {
        long rBound=LONG_MAX,lBound=LONG_MIN;

        return isValid(root,lBound,rBound);

    }
};