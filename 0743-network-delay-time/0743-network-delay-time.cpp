class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            int u = pq.top().second;
            int currDis = pq.top().first;

            pq.pop();

            if (currDis > dis[u]) {
                continue;
            }

            for (auto& i : adj[u]) {
                if (currDis + i.second < dis[i.first]) {
                    dis[i.first] = currDis + i.second;
                    pq.push({dis[i.first], i.first});
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) {
                return -1;
            }
        }

        return *max_element(dis.begin() + 1, dis.end());
    }
};