class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, n = s.length();
        for ( ;i < n && s[i] == ' '; i++) // Skip leading whitespace
            ;
        if (i < n && (s[i] == '+' || s[i] == '-')) { // Check for optional sign
            sign = (s[i++] == '-') ? -1 : 1;
        }
        long num = 0;
        while (i < n && isdigit(s[i]) && num <= INT_MAX) { // Convert digits to number
            num = num * 10 + (s[i++] - '0');
        }
        num = std::max(sign * num, (long) INT_MIN);
        num = std::min(num, (long) INT_MAX);
        return (int) num;
    }
};