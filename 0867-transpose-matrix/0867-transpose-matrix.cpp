class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < n; i++) {
            vector<int> level;
            for (int j = 0; j < m; j++) {
                level.push_back(matrix[j][i]);
            }
            ans.push_back(level);
        }

        return ans;
    }
};