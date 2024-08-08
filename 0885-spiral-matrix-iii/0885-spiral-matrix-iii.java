public class Solution {

    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int totalCells = rows * cols;
        int[][] ans = new int[totalCells][2];

        int layer = Math.max(Math.max(rows - rStart, cols - cStart), Math.max(rStart + 1, cStart + 1)) + 1;
        int i = rStart, j = cStart, k = 0;

        ans[k++] = new int[]{i, j};

        for (int m = 1; k < totalCells; m++) {
            int di = 0, dj = 1, step = 2 * m - 1; // rightward
            for (int a = 0; a < step && k < totalCells; a++) {
                i += di;
                j += dj;
                if (inside(i, j, rows, cols)) ans[k++] = new int[]{i, j};
            }
            di = 1; dj = 0; // downward
            for (int a = 0; a < step && k < totalCells; a++) {
                i += di;
                j += dj;
                if (inside(i, j, rows, cols)) ans[k++] = new int[]{i, j};
            }
            di = 0; dj = -1; // leftward
            step++; // increase step
            for (int a = 0; a < step && k < totalCells; a++) {
                i += di;
                j += dj;
                if (inside(i, j, rows, cols)) ans[k++] = new int[]{i, j};
            }
            di = -1; dj = 0; // upward
            for (int a = 0; a < step && k < totalCells; a++) {
                i += di;
                j += dj;
                if (inside(i, j, rows, cols)) ans[k++] = new int[]{i, j};
            }
        }

        return ans;
    }

    private boolean inside(int i, int j, int rows, int cols) {
        return (i >= 0) && (i < rows) && (j >= 0) && (j < cols);
    }
}
