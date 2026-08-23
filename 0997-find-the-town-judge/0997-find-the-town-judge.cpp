class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1);
        vector<int> outdegree(n + 1);
        for (auto& edge : trust) {
            int u = edge[0];
            int v = edge[1];

            indegree[v] += 1;
            outdegree[u] += 1;
        }

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};