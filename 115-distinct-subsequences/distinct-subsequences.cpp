class Solution {
public:
    int recurse(string s, string t,int ind1, int ind2,vector<vector<int>>& dp){
        if(ind2==t.size()){
            return 1;
        }
        if(ind1==s.size()){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(s[ind1]==t[ind2]){
            dp[ind1][ind2]=recurse(s,t,ind1+1,ind2+1,dp)+recurse(s,t,ind1+1,ind2,dp);
        }
        else{
            dp[ind1][ind2]=recurse(s,t,ind1+1,ind2,dp);
        }
        return dp[ind1][ind2];
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return recurse(s,t,0,0,dp);

    }
};