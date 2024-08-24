class Solution {
public:
    void solve(vector<string>& sol,string currString,int numOpen,int numClosed){
        if(numOpen==0&&numClosed==0){
            sol.push_back(currString);
            return;
        }
        else if(numOpen<0||numClosed<numOpen){
            return;
        }
        solve(sol,currString+'(',numOpen-1,numClosed);
        solve(sol,currString+')',numOpen,numClosed-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        solve(sol,"",n,n);
        return sol;
    }
};