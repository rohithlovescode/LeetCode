class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m=ob.size(),n=ob[0].size();
        cout<<n<<" "<<m;
        if(ob[m-1][n-1]==1 || ob[0][0]==1) return 0;
        if(m==1 && n==1 && ob[0][0]==0) return 1;
        for(int i=1;i<m;i++){
           if(ob[i][0]==0) ob[i][0]=-1;
           else break;
        }
        for(int i=1;i<n;i++){
           if(ob[0][i]==0) ob[0][i]=-1;
           else break;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(ob[i][j]==1) continue;
                if(ob[i][j-1]!=1) ob[i][j]=ob[i][j-1]; 
                if(ob[i-1][j]!=1) ob[i][j]+=ob[i-1][j]; 
            }
        }
        return (-ob[m-1][n-1]);
    }
};