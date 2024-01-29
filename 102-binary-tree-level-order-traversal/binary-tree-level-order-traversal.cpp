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
    void findLevelOrder(TreeNode* root,int level,vector<vector<int>> &ans){
        if(root==nullptr){
            return;
        }
        if(ans.size()<=level){
            ans.resize(level+1);
        }
        ans[level].push_back(root->val);

        findLevelOrder(root->left,level+1,ans);
        findLevelOrder(root->right,level+1,ans);

    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int level=0;
        findLevelOrder(root,level,ans);
        return ans;
    }
};