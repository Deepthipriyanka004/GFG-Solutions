import java.util.*;

class Solution {
    public int minCostPath(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        int[][] dist = new int[n][m];
        for (int[] row : dist) Arrays.fill(row, Integer.MAX_VALUE);

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[]{0, 0, 0}); // effort, row, col
        dist[0][0] = 0;

        int[] dr = {0, 0, 1, -1};
        int[] dc = {1, -1, 0, 0};

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int effort = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (r == n - 1 && c == m - 1) return effort;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {

                    int diff = Math.abs(mat[r][c] - mat[nr][nc]);
                    int newEffort = Math.max(effort, diff);

                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.add(new int[]{newEffort, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
}