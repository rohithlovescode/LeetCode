class Solution {
    void inOrderTraversal(vector<int> & inOrder,TreeNode* root){
        if(root==NULL){
            return;
        }

        inOrderTraversal(inOrder, root->left);
        inOrder.push_back(root->val);
        inOrderTraversal(inOrder, root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrder;
        inOrderTraversal(inOrder,root);
        int left=0;
        int right=inOrder.size()-1;
        while(left<right){
            int sum=inOrder[left]+inOrder[right];
            if(sum==k){
                return true;
            }
            if(sum<k){
                left++;
            }else{
                right--;
            }
        }
        return false;
    }
};