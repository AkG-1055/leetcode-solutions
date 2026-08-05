class Solution {
public:
    void dfs(int& near, vector<vector<int>>& adj, vector<bool>& isSup) {
        if (isSup[near])
            return;

        isSup[near] = true;

        for (int neighbour : adj[near]) {
            dfs(neighbour, adj, isSup);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<bool> isSup(n, false);
        vector<int> ans;
        bool canRemove = true;

        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }
    
        dfs(k, adj, isSup);

        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!isSup[u] &&isSup[v]) {
                canRemove = false;
                break;
            }
        }

        if(!canRemove) {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        }
        else{
            for (int i = 0; i < n; i++) {
                if(!isSup[i]) {
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};