class Solution {
public:
    bool isSafe(int i,int j,vector<string> curr,int n){
        for(int a=0;a<n;a++){
            if(curr[a][j]=='Q'){
                return false;
            }
        }
        for(int b=0;b<n;b++){
            if(curr[i][b]=='Q'){
                return false;
            }
        }
        for(int a=i,b=j;a>=0&&b>=0;a--,b--){
            if(curr[a][b]=='Q'){
                return false;
            }
        }
        for(int a=i,b=j;a<n&&b>=0;a++,b--){
            if(curr[a][b]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(int n, int col,vector<string>& curr,vector<vector<string>>& sol){
        if(col>=n){
            sol.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,col,curr,n)){
                curr[i][col]='Q';
                solve(n,col+1,curr,sol);
                curr[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp;
        string nullString(n,'.');
        
        vector<string> curr(n,nullString);
        vector<vector<string>> sol;

        int col=0;
        solve(n,col,curr,sol);

        return sol;
    }
};