class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> uniquePath(m,vector<int>(n,0));
        uniquePath[0][0] = 1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0) uniquePath[i][j]+=uniquePath[i-1][j];
                if(j>0) uniquePath[i][j]+=uniquePath[i][j-1];
            }
        }
        return uniquePath[m-1][n-1];
    }
};