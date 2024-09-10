class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||visited[i][j]==true||grid[i][j]==0){
            return 0;
        }
        visited[i][j]=true;
        return 1+dfs(grid,visited,i+1,j)+dfs(grid,visited,i,j+1)+dfs(grid,visited,i-1,j)+dfs(grid,visited,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&!visited[i][j]){
                    int tempAns=dfs(grid,visited,i,j);
                    ans=max(tempAns,ans);
                }
            }
        }
        return ans;
    }
};