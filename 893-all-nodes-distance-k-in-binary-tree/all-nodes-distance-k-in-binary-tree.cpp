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
            TreeNode* front=q.front(); q.pop();
            if(dist>k) break;

            if(front->val==-1){
                dist++;
                if(q.empty()) break;
                q.push(front);
                continue;
            }
            visited[front]=true;
            cout<<front->val<<" "<<dist<<endl;
            if(dist==k){
                ans.push_back(front->val);
            }

            if(parent[front] && !visited[parent[front]]){
                q.push(parent[front]);
            }
            if(front->left && !visited[front->left]){
                q.push(front->left);
            }
            if(front->right && !visited[front->right]){
                q.push(front->right);
            }

        }
        return ans;
    }
};