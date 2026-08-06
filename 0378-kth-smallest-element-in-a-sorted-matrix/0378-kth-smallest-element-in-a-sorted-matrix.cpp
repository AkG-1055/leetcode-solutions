class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pq.push(matrix[i][j]);
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans[ans.size() - k];
    }
};