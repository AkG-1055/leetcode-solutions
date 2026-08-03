class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                } else {
                    ans[i][j] = INT_MAX;
                }
            }
        }

        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int row = curr.first;
            int col = curr.second;

            for (auto dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    ans[newRow][newCol] == INT_MAX) {

                    ans[newRow][newCol] = ans[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return ans;
    }
};