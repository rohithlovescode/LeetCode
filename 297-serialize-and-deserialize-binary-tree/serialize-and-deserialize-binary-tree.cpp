class Codec {
public:
    string serialize(TreeNode* root) {
        string serStr = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == NULL) {
                serStr += "#,";
                continue;
            } else {
                serStr += to_string(front->val);
                serStr += ',';
            }
            q.push(front->left);
            q.push(front->right);
        }
        cout<<serStr<<endl;
        return serStr;
    }

    TreeNode* deserialize(string data) {
        if (data == "" || data == "#,") return nullptr;
        int ind=0;
        TreeNode* root=nullptr;
        vector<TreeNode*> treeVec;

        while(ind<data.length()){
            int nextComma=data.find(',',ind);
            string val=data.substr(ind,nextComma-ind);
            if(val=="#") treeVec.push_back(nullptr);
            else{
                TreeNode* newNode= new TreeNode(stoi(val));
                treeVec.push_back(newNode);
            }
            ind=nextComma+1;
        }
        int setInd=0,moveInd=1;

        while(moveInd<treeVec.size()){
            if(treeVec[setInd]==nullptr) {
                setInd++;
                continue;
            }
            treeVec[setInd]->left=treeVec[moveInd++];
            treeVec[setInd]->right=treeVec[moveInd++];
            setInd++;

        }
        return treeVec[0];
        
        return root;
    }
};