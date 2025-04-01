class Solution {
public:
    int solve(int left,int right,vector<int>& cuts,vector<bool>& visited,
        map<pair<int,int>,int>& dp){
        if(left>=right){
            return 0;
        }
        if(dp[{left,right}]!=0){
            return dp[{left,right}];
        }
        int ans=INT_MAX;
        for(int i=0;i<cuts.size();i++){
            
            int curr=right-left;
            if(!visited[i] && left<cuts[i]&&right>cuts[i]){
                visited[i]=true;
                int temp=curr+solve(left,cuts[i],cuts,visited,dp)+solve(cuts[i],right,cuts,visited,dp);
                visited[i]=false;
                ans=min(ans,temp);
            }
        }


        dp[{left,right}] = ans==INT_MAX? 0:ans;
        return dp[{left,right}];
    }
    int minCost(int n, vector<int>& cuts) {
        int size=cuts.size();
        map<pair<int,int>,int> dp;
        vector<bool> visited(size,false);
        return solve(0,n,cuts,visited,dp);
    }
};