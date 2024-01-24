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
private:
    void solve(TreeNode* curr,int &ans,vector<int> arr){
        if(curr==nullptr){
            return;
        }
        arr[curr->val]++;
        if(curr->left==nullptr&&curr->right==nullptr){
            int oneFreq=0;
            for(int i=0;i<10;i++){
                if(arr[i]%2==1)
                    oneFreq++;
            }
            if(oneFreq<=1){
                ans++;
            }
        }
        solve(curr->left,ans,arr);
        solve(curr->right,ans,arr);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        vector<int> arr(10,0);
        solve(root,ans,arr);
        return ans;
    }
};