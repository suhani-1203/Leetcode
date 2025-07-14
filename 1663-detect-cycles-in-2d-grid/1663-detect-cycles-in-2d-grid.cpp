class Solution {
public:
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& visited,
             int row, int col, int prow, int pcol, int m, int n) {
        visited[row][col] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < m &&
                ncol >= 0 && ncol < n &&
                grid[nrow][ncol] == grid[row][col]) {

                if (!visited[nrow][ncol]) {
                    if (dfs(grid, visited, nrow, ncol, row, col, m, n))
                        return true;
                }
                else if (nrow != prow || ncol != pcol) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, m, n))
                        return true;
                }
            }
        }
        return false;
    }
};
