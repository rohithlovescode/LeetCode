class Solution {
public:
    string reverseWords(string s) {
        // Trim leading and trailing spaces and reduce multiple spaces to one
        int i = 0, j = 0, n = s.length();
        while (i < n && s[i] == ' ') i++; // Skip leading spaces
        while (i < n) {
            if (s[i] != ' ') {
                s[j++] = s[i++]; // Copy non-space characters
            } else {
                // Replace multiple spaces with a single space
                s[j++] = ' ';
                while (i < n && s[i] == ' ') i++;
            }
        }
        if (j > 0 && s[j - 1] == ' ') j--; // Remove trailing space
        s.resize(j); // Resize string to remove extra characters

        // Reverse the entire string
        reverse(s.begin(), s.end());

        // Reverse each word in the string
        int start = 0;
        for (int k = 0; k <= s.length(); k++) {
            if (k == s.length() || s[k] == ' ') {
                reverse(s.begin() + start, s.begin() + k);
                start = k + 1;
            }
        }

        return s;
    }
};
