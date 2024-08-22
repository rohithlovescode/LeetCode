class Solution {
public:
    int totalNQueens(int n) {
        if (n == 1)
            return 1;
        if (n <= 3)
            return 0;
        col = vector<bool> (n, false);
        dig = vector<bool> (2*n - 1, false);
        crdig = vector<bool> (2*n - 1, false);

        backTrack(n, 0);
        return ans;
    }
private:
    int ans;
    vector<bool> col;
    vector<bool> dig;
    vector<bool> crdig;

    void backTrack(int n, int lvl) {
        if (lvl == n) {
            ans++;
            return;
        }
        int toAdd = n - 1;
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dig[lvl + i] && !crdig[lvl - i + toAdd]) {
                col[i] = dig[lvl + i] = crdig[lvl - i + toAdd] = true;
                backTrack(n, lvl + 1);
                col[i] = dig[lvl + i] = crdig[lvl - i + toAdd] = false;
            }
        }

    }
};