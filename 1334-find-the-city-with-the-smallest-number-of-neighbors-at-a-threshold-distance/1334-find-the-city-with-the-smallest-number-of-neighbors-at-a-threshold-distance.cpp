class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dis[i][i] = 0;
            for (auto j : adj[i]) {
                dis[i][j.first] = j.second;
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX) {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
        }

        int min_count = INT_MAX;
        int index = -1;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dis[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (min_count > count) {
                min_count = count;
                index = i;
            }
            if (min_count == count) {
                if (i > index) {
                    index = i;
                }
            }
        }
        return index;
    }
};