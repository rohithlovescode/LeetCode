class Solution {
public:
    void addNeighbors(vector<vector<int>>& grid,queue<pair<int,int>>& q,int i,int j,vector<vector<bool>>& visited,int& numOranges){
        if(i-1>=0&&visited[i-1][j]==false&&grid[i-1][j]==1){
            numOranges--;
            q.push({i-1,j});
            visited[i-1][j]=true;
        }
        if(j-1>=0&&visited[i][j-1]==false&&grid[i][j-1]==1){
            numOranges--;
            q.push({i,j-1});
            visited[i][j-1]=true;
        }
        if(i+1<grid.size()&&visited[i+1][j]==false&&grid[i+1][j]==1){
            numOranges--;
            q.push({i+1,j});
            visited[i+1][j]=true;
        }
        if(j+1<grid[0].size()&&visited[i][j+1]==false&&grid[i][j+1]==1){
            numOranges--;
            q.push({i,j+1});
            visited[i][j+1]=true;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int freshOranges=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    freshOranges++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        int ans=0;
        while(!q.empty()&&freshOranges>0){
            ans++;

            int size=q.size();
            while(size--){
                pair<int,int> front = q.front();
                q.pop();
                addNeighbors(grid,q,front.first,front.second,visited,freshOranges);
            }
        }
        if(freshOranges==0){
            return ans;
        }
        return -1;
    }
};