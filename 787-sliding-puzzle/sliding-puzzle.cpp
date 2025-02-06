class Solution {
public:
    vector<vector<int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
    int m,n;
    void pushAdj(queue<vector<vector<int>>>& q,map<vector<vector<int>>,bool>& visited){
        int x,y;
        vector<vector<int>> front=q.front();
        q.pop();
        for(int i=0;i<front.size();i++){
            for(int j=0;j<front[0].size();j++){
                if(front[i][j]==0){
                    x=i;
                    y=j;
                    break;
                }
            }
        }

        for(auto dir: dirs){
            int new_x=dir[0]+x;
            int new_y=dir[1]+y;
            if(new_x>=0&&new_x<m&&new_y>=0&&new_y<n){
                swap(front[new_x][new_y],front[x][y]);
                if(!visited[front]){
                    visited[front]=true;
                    q.push(front);
                }
                swap(front[new_x][new_y],front[x][y]);
            }
        }

    }
    int slidingPuzzle(vector<vector<int>>& board) {
        m=2,n=3;
        vector<vector<int>> target={{1,2,3},{4,5,0}};
        int count=0;
        map<vector<vector<int>>,bool> visited;
        queue<vector<vector<int>>> q;
        q.push(board);
        visited[board]=true;

        while(!q.empty()){
            int leng=q.size();
            while(leng--){
                if(q.front()==target){
                    return count;
                }
                pushAdj(q,visited);
            }
            count++;
              
        }
        return -1;


    }
};