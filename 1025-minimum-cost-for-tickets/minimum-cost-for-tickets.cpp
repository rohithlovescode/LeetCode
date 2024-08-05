class Solution {
public:
    int findNext(int solvedUntil,vector<int> & days){
        int n=days.size();
        for(int i=0;i<n;i++){
            if(solvedUntil<=days[i]){
                return days[i];
            }
        }
        return -1;
    }
    int solve(int solvedUntil,vector<int> & days, vector<int> & costs,vector<int> & dp){
        if(solvedUntil<366&&dp[solvedUntil]!=-1){
            return dp[solvedUntil];
        }
        int next=findNext(solvedUntil,days);
        if(next==-1){
            return 0;
        }
        if(dp[next]!=-1){
            return dp[next];
        }
        int a=costs[0]+solve(next+1,days,costs,dp);
        int b=costs[1]+solve(next+7,days,costs,dp);
        int c=costs[2]+solve(next+30,days,costs,dp);

        int sol= min(a,min(b,c));
        for(int i=solvedUntil;i<=next;i++){
            dp[i]=sol;
        }
        return sol;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int solvedUntil=1;
        vector<int> dp(366,-1);
        return solve(solvedUntil,days,costs,dp);
    }
};