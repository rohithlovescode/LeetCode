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
    int diameterOfBinaryTree(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<TreeNode*,bool> visited;
        unordered_map<TreeNode*,int> depth;
        depth[nullptr]=0;
        int diameter=0;

        while(!st.empty()){
            TreeNode* top=st.top();
            if(visited[top]){
                st.pop();
                depth[top]=max(depth[top->left],depth[top->right])+1;
                diameter=max(diameter,depth[top->left]+depth[top->right]);
            }else{
                visited[top]=true;

                if(top->left!=nullptr) st.push(top->left);
                if(top->right!=nullptr) st.push(top->right);
            }

        }
        return diameter;
    }
};