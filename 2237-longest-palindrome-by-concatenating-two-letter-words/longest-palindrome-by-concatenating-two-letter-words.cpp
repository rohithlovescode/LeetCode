class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // 2D array to act as a frequency map for 2-letter words
        int freq[26][26] = {0};
        int ans = 0;

        for (const string& w : words) {
            int a = w[0] - 'a';
            int b = w[1] - 'a';

            // If the reverse ("ba") exists, pair them up
            if (freq[b][a] > 0) {
                ans += 4;
                freq[b][a]--;
            } else {
                // Otherwise, store current word "ab"
                freq[a][b]++;
            }
        }

        // Check for a single "aa" type word to put in the very middle
        for (int i = 0; i < 26; i++) {
            if (freq[i][i] > 0) {
                ans += 2;
                break;
            }
        }

        return ans;
    }
};