class Solution {
public:
    void dfs (int i, int j, vector<vector<int>>& grid, int& count) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;

        dfs(i - 1, j, grid, count);
        dfs(i + 1, j, grid, count);
        dfs(i, j - 1, grid, count);
        dfs(i, j + 1, grid, count);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            if (grid[i][0]) dfs(i, 0, grid, count);
            if (grid[i][n - 1]) dfs(i, n - 1, grid, count);
        }

        for (int i = 0; i < n; i++) {
            if (grid[0][i]) dfs(0, i, grid, count);
            if (grid[m - 1][i]) dfs(m - 1, i, grid, count);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};