class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vec(2 * n - 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ind = i - j + n - 1;
                vec[ind].push_back(grid[i][j]);
            }
        }
        int i=0;
        for (auto& v : vec) {
            sort(v.begin(), v.end());
            if(i>=n-1)
            reverse(v.begin(),v.end());
            i++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ind = i - j + n - 1;
                int k = (ind >= n) ? (i - (ind - n + 1)) : i;
                grid[i][j] = vec[ind][k];
            }
        }

        return grid;
    }
};
