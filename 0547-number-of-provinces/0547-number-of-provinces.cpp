class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[node] = true;

        for (int near = 0; near < isConnected.size(); near++) {
            if (isConnected[node][near] == 1 && visited[near] == false) {
                dfs(near, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        for (int node = 0; node < n; node++){
            if (visited[node] == false) {
                count++;
                dfs(node, isConnected, visited);
            }
        }

        return count;
    }
};