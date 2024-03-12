class Solution {
    int solve(string& text1, string& text2, vector<vector<int>>& dp, int i, int j) {
        if (i == 0 || j == 0)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (text1[i - 1] == text2[j - 1])
            dp[i][j] = 1 + solve(text1, text2, dp, i - 1, j - 1);
        else
            dp[i][j] = max(solve(text1, text2, dp, i - 1, j), solve(text1, text2, dp, i, j - 1));
        
        return dp[i][j];
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int leng1 = text1.length();
        int leng2 = text2.length();

        vector<vector<int>> dp(leng1 + 1, vector<int>(leng2 + 1, -1));
        return solve(text1, text2, dp, leng1, leng2);
    }
};