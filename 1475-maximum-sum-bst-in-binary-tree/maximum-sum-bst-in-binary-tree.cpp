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
    pair<int, pair<int, int>> solve(TreeNode* root, int& maxi){
        if(root==NULL) return {0, {INT_MAX, INT_MIN}};
        
        pair<int, pair<int, int>> lft = solve(root->left, maxi);
        pair<int, pair<int, int>> rht = solve(root->right, maxi);
        int sum = lft.first+rht.first;

        if(root->val>lft.second.second && root->val<rht.second.first) {
            maxi = max(sum+root->val, maxi);
            return {sum+root->val, {min(root->val, lft.second.first), max(root->val, rht.second.second)}};
        }
        else{
            maxi = max(maxi, max(lft.first, rht.first));
            return {max(lft.first, rht.first), {INT_MIN, INT_MAX}};
        }
        
    }
    int maxSumBST(TreeNode* root) {
        int maxi = INT_MIN;
        pair<int, pair<int, int>> ans = solve(root, maxi);
        if(maxi<=0) return 0;
        return maxi;
    }
};