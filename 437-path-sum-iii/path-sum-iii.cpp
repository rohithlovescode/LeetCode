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
    int MOD=1e9+7;
    int prefixTree(TreeNode* curr, vector<int>& prefixSum,int& targetSum){
        if(curr==NULL){
            return 0;
        }
        prefixSum.push_back(curr->val);
        int temp=0;
        int count =0;
        for(int i=prefixSum.size()-1;i>=0;i--){
            temp=(temp+prefixSum[i])%MOD;
            if(temp==targetSum) {
                count++;
            }
        }
        int ans= count+prefixTree(curr->left,prefixSum,targetSum)+
                prefixTree(curr->right,prefixSum,targetSum);
        prefixSum.pop_back();
        return ans;
        

    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> prefixSum;
        return prefixTree(root,prefixSum,targetSum);
    }
};