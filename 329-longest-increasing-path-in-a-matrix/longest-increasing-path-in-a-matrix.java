class Solution {
    public int longestIncreasingPath(int[][] matrix) {

        int m = matrix.length;
        int n = matrix[0].length;
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // generating the indegree array
        // note that we have M*N nodes
        int[][] indegree = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int[] dir : dirs) {
                    int nx = i + dir[0];
                    int ny = j + dir[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        if (matrix[nx][ny] > matrix[i][j]) {
                            // SMALLER       LARGER
                            // node(i,j) --> node(nx,ny)
                            indegree[nx][ny]++;
                        }
                    }
                }
            }
        }


        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (indegree[i][j] == 0) {
                    queue.add(new int[]{i, j});
                }
            }
        }

        int length = 0;

        while (!queue.isEmpty()) {
            // level by level
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] cur = queue.poll();
                int x = cur[0];
                int y = cur[1];

                for (int[] dir: dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        // note that indegree[x][y] is zero
                        if (matrix[x][y] < matrix[nx][ny]) {
                            indegree[nx][ny]--;
                            if (indegree[nx][ny] == 0) {
                                queue.offer(new int[]{nx, ny});
                            }
                        }
                    }
                }
            }
            length++;
        }

        return length;
    }
}