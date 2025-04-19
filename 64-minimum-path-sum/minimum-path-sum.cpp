class Solution {
public:
    int solve(vector<vector<int>>& grid, int i,int j,vector<vector<int>>& dp){
        if(i==grid.size()-1&&j==grid[0].size()-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int mini=INT_MAX;
        if(i!=grid.size()-1){
            int temp=solve(grid,i+1,j,dp);
            mini=min(temp,mini);
        }
        if(j!=grid[0].size()-1){
            int temp=solve(grid,i,j+1,dp);
            mini=min(temp,mini);
        }
        dp[i][j]=grid[i][j]+mini;
        return dp[i][j];

    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));

        return solve(grid,0,0,dp);        
    }
};