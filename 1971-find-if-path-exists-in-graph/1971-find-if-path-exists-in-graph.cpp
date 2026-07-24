class Solution {
public:
    bool dfs(int start, vector<vector<int>>& neighbours, vector<bool>& visited,
             int destination) {
        visited[start] = true;

        for (int next : neighbours[start]) {
            if (visited[next] == false) {
                if (next == destination) {
                    return true;
                } 
                else {
                    if (dfs(next, neighbours, visited, destination)) {
                        return true;
                    };
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if (source == destination) {
            return true;
        }

        vector<vector<int>> neighbours(n);
        vector<bool> visited(n, false);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            neighbours[u].push_back(v);
            neighbours[v].push_back(u);
        }

        return dfs(source, neighbours, visited, destination);
    }
};