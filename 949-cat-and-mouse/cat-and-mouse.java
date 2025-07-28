class Solution {
    public int catMouseGame(int[][] graph) {
        int n = graph.length;
        // (cat, mouse, mouseMove = 0)
        int[][][] color = new int[n][n][2];
        int[][][] outdegree = new int[n][n][2];
        for (int i = 0; i < n; i++) { // cat
            for (int j = 0; j < n; j++) { // mouse
                outdegree[i][j][0] = graph[j].length;
                outdegree[i][j][1] = graph[i].length;
                for (int k : graph[i]) {
                    if (k == 0) {
                        outdegree[i][j][1]--;
                        break;
                    }
                }
            }
        }
        Queue<int[]> q = new LinkedList<>();
        for (int k = 1; k < n; k++) {
            for (int m = 0; m < 2; m++) {
                color[k][0][m] = 1;
                q.offer(new int[]{k, 0, m, 1});
                color[k][k][m] = 2;
                q.offer(new int[]{k, k, m, 2});
            }
        }
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cat = cur[0], mouse = cur[1], mouseMove = cur[2], c = cur[3];
            if (cat == 2 && mouse == 1 && mouseMove == 0) {
                return c;
            }
            int prevMouseMove = 1 - mouseMove;
            for (int prev : graph[prevMouseMove == 1 ? cat : mouse]) {
                int prevCat = prevMouseMove == 1 ? prev : cat;
                int prevMouse = prevMouseMove == 1 ? mouse : prev;
                if (prevCat == 0) {
                    continue;
                }
                if (color[prevCat][prevMouse][prevMouseMove] > 0) {
                    continue;
                }
                if (prevMouseMove == 1 && c == 2 || prevMouseMove == 0 && c == 1
                    || --outdegree[prevCat][prevMouse][prevMouseMove] == 0) {
                    color[prevCat][prevMouse][prevMouseMove] = c;
                    q.offer(new int[]{prevCat, prevMouse, prevMouseMove, c});
                }
            }
        }
        return color[2][1][0];
    }
}