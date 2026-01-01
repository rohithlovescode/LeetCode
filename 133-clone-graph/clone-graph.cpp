/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,map<int,Node*> &mapp){
        if(!node) {
            return nullptr;
        }

        if(mapp.count(node->val)!=0){
            return mapp[node->val];
        }
        Node* newNode=new Node(node->val);
        mapp[node->val]=newNode;

        for(auto neigh: node->neighbors){
            newNode->neighbors.push_back(dfs(neigh,mapp));
        }

        return newNode;
    }
    Node* cloneGraph(Node* node) {
        map<int,Node*> mapp;

        return dfs(node,mapp);
    }
};