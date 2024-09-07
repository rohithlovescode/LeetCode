class Solution {
public:
    TreeNode* build(vector<int> & preorder,vector<int>& inorder,
    int& preOrderIndex,int fromIndex,int toIndex){
        if(toIndex<fromIndex){
            return nullptr;
        }
        int index=-1;
        for(int i=fromIndex;i<=toIndex;i++){
            if(inorder[i]==preorder[preOrderIndex]){
                index=i;
                break;
            }
        }
        if(index==-1){
            return nullptr;
        }
        TreeNode* newNode=new TreeNode(inorder[index]);
        preOrderIndex++;
        newNode->left=build(preorder,inorder,preOrderIndex,fromIndex,index-1);
        newNode->right=build(preorder,inorder,preOrderIndex,index+1,toIndex);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        int fromIndex=0;
        int toIndex=inorder.size()-1;
        return build(preorder, inorder, preOrderIndex, fromIndex, toIndex);
    }
};