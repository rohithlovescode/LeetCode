class Solution {
    int solve(string& text1 , string& text2 , vector<vector<int>>& dp,int ind1,int ind2){
        if(ind1==-1||ind2==-1){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        else if(text1[ind1]==text2[ind2]){
            dp[ind1][ind2]= 1+solve(text1,text2,dp,ind1-1,ind2-1);
            
            return dp[ind1][ind2];
        }
        else{//text1[leng1-1]!=text2[leng2-1]
            int left=solve(text1,text2,dp,ind1-1,ind2);
            int right=solve(text1,text2,dp,ind1,ind2-1);
            dp[ind1][ind2]=max(left,right);
            
            return dp[ind1][ind2];
        }
        

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ind1=text1.length()-1;
        int ind2=text2.length()-1;

        vector<vector<int>> dp(ind1+1,vector<int> (ind2+1,-1));
        return solve(text1,text2,dp,ind1,ind2);
    }
};