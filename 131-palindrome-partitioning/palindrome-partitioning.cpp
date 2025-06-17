class Solution {
private:
    void sub(int ind, string s, vector<string>& temp, vector<vector<string>>& res) {
        if (ind == s.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = ind; i < s.size(); i++) {
            if (ispalindrome(ind, i, s)) {
                temp.push_back(s.substr(ind, i - ind + 1));
                sub(i + 1, s, temp, res);
                temp.pop_back();  // backtrack
            }
        }
    }

    bool ispalindrome(int start, int end, string s) {
        while (start <= end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        sub(0, s, temp, res);
        return res;
    }
};