class Solution {
public:
    void recurse(vector<vector<int>>& mat,int i, int j,vector<vector<int>> & path,int& maxi){
        if(i<0||j<0||i>=mat.size()||j>=mat[0].size()){
            return;
        }
        if(path[i][j]!=0){
            return;
        }
        int maxNeighbor=0;
        //top
        if(i!=0&&mat[i-1][j]>mat[i][j]){
            recurse(mat,i-1,j,path,maxi);
            maxNeighbor=max(maxNeighbor,path[i-1][j]);
        }
        //left
        if(j!=0&&mat[i][j-1]>mat[i][j]){
            recurse(mat,i,j-1,path,maxi);
            maxNeighbor=max(maxNeighbor,path[i][j-1]);
        }
        //bottom
        if(i+1!=mat.size()&&mat[i+1][j]>mat[i][j]){
            if(path[i+1][j]==0){
                recurse(mat,i+1,j,path,maxi);
            }
            maxNeighbor=max(maxNeighbor,path[i+1][j]);
        }
        //right
        if(j+1!=mat[0].size()&&mat[i][j+1]>mat[i][j]){
            if(path[i][j+1]==0){
                recurse(mat,i,j+1,path,maxi);
            }
            maxNeighbor=max(maxNeighbor,path[i][j+1]);
        }
        path[i][j]=1+maxNeighbor;
        maxi=max(maxi,path[i][j]);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> path(matrix.size(),vector<int>(matrix[0].size(),0));
        int maxi=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                recurse(matrix,i,j,path,maxi);
                
            }
        }
        return maxi;
    }
};