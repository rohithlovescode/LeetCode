class Solution {
public:
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        // Base Cases
        if (i < 0 && j < 0) return true;  // Both strings are fully matched
        if (i >= 0 && j < 0) return false;  // Pattern exhausted but string still has characters
        if (i < 0 && j >= 0) {
            // Check if the remaining characters in the pattern are all '*'
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        // Check if the current state has already been computed
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match or pattern has '?', recurse for the next pair
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        }
        
        // If pattern has '*', it can match zero or more characters
        if (p[j] == '*') {
            return dp[i][j] = (solve(s, p, i, j - 1, dp) || solve(s, p, i - 1, j, dp));
        }

        // If characters don't match and no wildcard, return false
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // Memoization table initialized with -1 (uncomputed states)
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Start the recursion from the end of the strings
        return solve(s, p, n - 1, m - 1, dp);
    }
};