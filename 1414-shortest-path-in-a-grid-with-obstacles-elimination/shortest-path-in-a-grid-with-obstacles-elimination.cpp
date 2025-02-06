class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> max_k(m, vector<int>(n, -1));
        queue<vector<int>> q; // Each element: {i, j, remaining_k, steps}
        q.push({0, 0, k, 0});
        max_k[0][0] = k;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            int i = current[0], j = current[1], curr_k = current[2], steps = current[3];
            
            if (i == m - 1 && j == n - 1) {
                return steps;
            }
            
            for (auto& dir : dirs) {
                int new_i = i + dir.first;
                int new_j = j + dir.second;
                
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                    int new_remaining_k = curr_k - grid[new_i][new_j];
                    if (new_remaining_k >= 0) {
                        if (max_k[new_i][new_j] < new_remaining_k) {
                            max_k[new_i][new_j] = new_remaining_k;
                            q.push({new_i, new_j, new_remaining_k, steps + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};