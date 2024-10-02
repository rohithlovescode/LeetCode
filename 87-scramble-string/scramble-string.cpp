class Solution {
public:
    unordered_map<string, bool> mp;
    bool helper(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        string key = s1 + "#" + s2;
        if (mp.find(key) != mp.end()) {
            return mp[key];
        }
        int n = s1.size();
        bool flag = false;
        for (int len = 1; len <= n - 1; len++) {
            bool swap = helper(s1.substr(0, len), s2.substr(n - len, len)) && helper(s1.substr(len, n - len), s2.substr(0, n - len));
            bool notSwap = helper(s1.substr(0, len), s2.substr(0, len)) && helper(s1.substr(len, n - len), s2.substr(len, n - len));
            if (swap || notSwap) {
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
    }
    bool isScramble(string s1, string s2) {
        return helper(s1, s2);
    }
};