class Solution {
private:
    bool dfs(int node,unordered_map<int,bool> &vis,unordered_map<int,bool> &completed
        ,vector<vector<int>> &adj){
        vis[node]=true;
        bool ans=true;
        for(auto it: adj[node]){
            if(vis[it]&&!completed[it]){
                return false;
            }
            if(!vis[it]){
                ans=ans && dfs(it,vis,completed,adj);
            }
        }
        completed[node]=true;
        return ans;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int,bool> vis,completed;
        bool ans=true;
        vector<vector<int>> adj(numCourses,vector<int>());

        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                ans=ans && dfs(i,vis,completed,adj);
            }
        }
        return ans;
    }
};