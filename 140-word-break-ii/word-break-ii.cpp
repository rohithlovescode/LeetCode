class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s, 0);
    }

    vector<string> dfs(const string& s, int start) {
        if (memo.count(start)) return memo[start];
        vector<string> result;
        if (start == s.size()) {
            result.push_back("");
            return result;
        }
        for (int end = start + 1; end <= s.size(); ++end) {
            string word = s.substr(start, end - start);
            if (dict.count(word)) {
                vector<string> subs = dfs(s, end);
                for (const string& sub : subs) {
                    result.push_back(word + (sub.empty() ? "" : " " + sub));
                }
            }
        }
        return memo[start] = result;
    }
};