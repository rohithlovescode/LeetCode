class Solution {
public:
    void dfs(int ind,vector<vector<int>>& graph,vector<bool>& visited,
            vector<int>& path,vector<vector<int>>& sol){
        
        if(ind==graph.size()-1){
            sol.push_back(path);
        }
        for( auto it: graph[ind]){
            if(!visited[it]){
                visited[it]=true;
                path.push_back(it);
                dfs(it,graph,visited,path,sol);
                path.pop_back();
                visited[it]=false;
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> visited(n,false);
        vector<int> path;
        vector<vector<int>> sol;
        path.push_back(0);
        dfs(0,graph,visited,path,sol);

        return sol;
        
    }
};