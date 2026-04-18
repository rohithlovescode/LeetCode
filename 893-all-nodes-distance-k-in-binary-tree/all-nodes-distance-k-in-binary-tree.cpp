/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent;
        vector<int> ans;

        if(!root) return ans;
        parent[root]=nullptr;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* top =st.top();
            st.pop();

            if(top->right){
                parent[top->right]=top;
                st.push(top->right);
            }
            if(top->left){
                parent[top->left]=top;
                st.push(top->left);
            }
        }

        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*,bool> visited;
        int dist=0;
        TreeNode* newNode=new TreeNode(-1);
        q.push(newNode);

        while(!q.empty()){
            TreeNode* top=q.front(); q.pop();
            if(dist>k) break;

            if(top->val==-1){
                dist++;
                if(q.empty()) break;
                q.push(top);
                continue;
            }
            visited[top]=true;
            cout<<top->val<<" "<<dist<<endl;
            if(dist==k){
                ans.push_back(top->val);
            }

            if(parent[top] && !visited[parent[top]]){
                q.push(parent[top]);
            }
            if(top->left && !visited[top->left]){
                q.push(top->left);
            }
            if(top->right && !visited[top->right]){
                q.push(top->right);
            }

        }
        return ans;
    }
};