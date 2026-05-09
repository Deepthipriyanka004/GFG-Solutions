class Solution {
  public:

    long long determinant(vector<vector<double>>& mat, int n) {

        double det = 1;

        for (int i = 0; i < n; i++) {

            int pivot = i;

            for (int j = i; j < n; j++) {
                if (abs(mat[j][i]) > abs(mat[pivot][i]))
                    pivot = j;
            }

            if (abs(mat[pivot][i]) < 1e-9)
                return 0;

            if (i != pivot) {
                swap(mat[i], mat[pivot]);
                det *= -1;
            }

            det *= mat[i][i];

            for (int j = i + 1; j < n; j++) {

                double factor = mat[j][i] / mat[i][i];

                for (int k = i; k < n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return round(det);
    }

    int countSpanTree(int n, vector<vector<int>>& edges) {

        if (n == 1) return 1;

        vector<vector<double>> lap(n, vector<double>(n, 0));

        // Build Laplacian matrix
        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;

            lap[u][v]--;
            lap[v][u]--;
        }

        // Cofactor matrix
        vector<vector<double>> cof(n - 1,
                                   vector<double>(n - 1));

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                cof[i][j] = lap[i][j];
            }
        }

        return determinant(cof, n - 1);
    }
};