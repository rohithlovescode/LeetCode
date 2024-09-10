class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||visited[i][j]==true||grid[i][j]=='0'){
            return;
        }

        
        visited[i][j]=true;
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int islands=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && visited[i][j]==false){
                    islands++;
                    dfs(grid,visited,i,j);
                }
            }
        }

        return islands;
    }
};