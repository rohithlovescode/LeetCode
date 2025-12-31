
class Solution {
public:
    bool isSameTree(TreeNode* node1,TreeNode* node2){
        if(node1==NULL&&node2==NULL)  return true;
        else if(node1==NULL||node2==NULL||node1->val!=node2->val) return false;
        
        return isSameTree(node1->left,node2->left)&&isSameTree(node1->right,node2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* top=st.top();
            st.pop();

            if(top->val==subRoot->val){
                if(isSameTree(top,subRoot)) return true;
            }

            if(top->left) st.push(top->left);
            if(top->right) st.push(top->right);
        }

        return false;
    }
};