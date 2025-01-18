class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        // Skip leading whitespace
        while (i < n && s[i] == ' ') i++;
        
        // Handle sign
        bool isNeg = false;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            isNeg = (s[i] == '-');
            i++;
        }
        
        // Convert digits
        int ans = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            // Check for overflow
            if (ans > (INT_MAX - digit) / 10) {
                return isNeg ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
            i++;
        }
        
        return isNeg ? -ans : ans;
    }
};
