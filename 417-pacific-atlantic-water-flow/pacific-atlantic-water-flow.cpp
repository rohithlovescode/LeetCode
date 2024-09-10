class Solution {
public:
    void dfs(vector<vector<int>>& heights,int i,int j,vector<vector<bool>>& visited){
        if(i<0||j<0||i>=heights.size()||j>=heights[0].size()||visited[i][j]){
            return;
        }
        visited[i][j]=true;
        if(i>0&&heights[i-1][j] >= heights[i][j])
            dfs(heights,i-1,j,visited);
        if(j>0&&heights[i][j-1] >= heights[i][j])
            dfs(heights,i,j-1,visited);
        if(i+1<heights.size() && heights[i+1][j] >= heights[i][j])
            dfs(heights,i+1,j,visited);
        if(j+1<heights[0].size() && heights[i][j+1] >= heights[i][j])
            dfs(heights,i,j+1,visited);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> pacificVisited(m,vector<bool>(n,false));
        vector<vector<bool>> atlanticVisited(m,vector<bool>(n,false));
        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            dfs(heights,i,0,pacificVisited);
        }
        for(int j=0;j<n;j++){
            dfs(heights,0,j,pacificVisited);
        }

        for(int i=0;i<m;i++){
            dfs(heights,i,n-1,atlanticVisited);
        }
        for(int j=0;j<n;j++){
            dfs(heights,m-1,j,atlanticVisited);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacificVisited[i][j]&&atlanticVisited[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;


    }
};