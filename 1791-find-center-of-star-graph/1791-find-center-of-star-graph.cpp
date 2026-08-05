class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 2);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < adj.size(); i++) {
            if (adj[i].size() == n) {
                return i;
            }
        }

        return 0;
    }
};