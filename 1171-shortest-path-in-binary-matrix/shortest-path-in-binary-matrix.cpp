class Solution {
public:
    vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1)    return -1;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        q.push({0,0});
        int ans=1;
        visited[0][0]=true;
        while(!q.empty()){
            int leng=q.size();

            for(int i=0;i<leng;i++){
                pair<int,int> front=q.front();
                q.pop();
                if(front.first==n-1&&front.second==n-1){
                    return ans;
                }
                for(auto dir:dirs){
                    int new_x=dir[0]+front.first;
                    int new_y=dir[1]+front.second;
                    if(new_x>=0&&new_x<n&&new_y>=0&&new_y<n&&!visited[new_x][new_y]&&grid[new_x][new_y]==0){
                        visited[new_x][new_y]=true;
                        q.push({new_x,new_y});
                        
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};