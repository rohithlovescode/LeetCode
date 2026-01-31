class Solution {
public:
    int topDown(string& text1, string& text2, int ind1,int ind2,vector<vector<int>>& dp){
        if(ind1>=text1.size()||ind2>=text2.size()) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(text1[ind1]==text2[ind2]) dp[ind1][ind2] = 1+topDown(text1,text2,ind1+1,ind2+1,dp);
        else dp[ind1][ind2] = max(topDown(text1,text2,ind1+1,ind2,dp),
                                    topDown(text1,text2,ind1,ind2+1,dp));
        return dp[ind1][ind2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length();
        int l2=text2.length();

        vector<vector<int>> dp(l1,vector<int>(l2,-1));

        return topDown(text1,text2,0,0,dp);//function names, hwo to determine
        
    }
};