class Solution {
public:
    vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));//also for visited
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        int count=1;

        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                pair<int,int> front=q.front();
                q.pop();
                
                for(auto dir:dirs){
                    int new_x=dir[0]+front.first;
                    int new_y=dir[1]+front.second;
                    if(new_x>=0 && new_x<m && new_y>=0 && new_y<n&&ans[new_x][new_y]==-1){
                        ans[new_x][new_y]=count;
                        q.push({new_x,new_y});
                    }
                }
                
            }
                count++;
        }



        return ans;
    }
};