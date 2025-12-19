class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});//representing increase in time

        int time=0;
        while(!q.empty()){
            int i,j;
            pair<int,int> front=q.front();
            i=front.first;
            j=front.second;
            q.pop();

            if(i==-1){
                time++;
                if(q.size()!=0){
                    q.push({-1,-1});
                }
            }else{
                if(i-1>=0&&grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                if(j-1>=0&&grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                if(i+1<grid.size()&&grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                if(j+1<grid[0].size()&&grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
            }
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time-1;
    }
};