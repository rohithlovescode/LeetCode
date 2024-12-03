class Solution {
public:
    int recurse(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i>=m||j>=n){
            return 0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        dp[i][j]= recurse(i+1,j,m,n,dp)+recurse(i,j+1,m,n,dp);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        grid[m-1][n-1]=1;
        return recurse(0,0,m,n,grid);
    }
};