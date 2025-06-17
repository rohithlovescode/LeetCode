class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val == key) return helper(root);

        TreeNode* dummy = root;
        while (root) {
            if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    TreeNode* helper(TreeNode* root) {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        if (!root->right) return root;
        return findLastRight(root->right);
    }
};