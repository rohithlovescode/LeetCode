class Solution {
public:
    int solve(vector<int>& values,int start,int end,vector<vector<int>>& dp){
        if(end-start==1){
            return 0;
        }
        if(end-start==2){
            return values[start]*values[start+1]*values[start+2];
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int mini=INT_MAX;

        for(int i=start+1;i<end;i++){
            mini=min(mini,values[i]*values[start]*values[end]+solve(values,start,i,dp)+solve(values,i,end,dp));
        }
        dp[start][end]=mini;
        return mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        int start=0;
        int end=values.size()-1;
        vector<vector<int>> dp(values.size(),vector<int> (values.size(),-1));

        return solve(values , start, end,dp);
    }
};