class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans;
        vector<int> level;

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int maxi = -1;
                for (int r = i; r <= i + 2; r++) {
                    for (int c = j; c <= j + 2; c++) {
                        maxi = max(maxi, grid[r][c]);
                    }
                }
                level.push_back(maxi);
            }
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};