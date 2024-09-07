class Solution {
public:
    bool validateBST(TreeNode* root, long long mini, long long maxi) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= mini || root->val >= maxi) {
            return false;
        }
        return validateBST(root->left, mini, root->val) && validateBST(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return validateBST(root, LLONG_MIN, LLONG_MAX);  // Use long long limits
    }
};
