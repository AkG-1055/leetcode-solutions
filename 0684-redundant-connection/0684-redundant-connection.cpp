class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);

            for (int i = 1; i < n + 1; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        void unionSets(int x, int y) {
            int xroot = find(x);
            int yroot = find(y);

            if (xroot == yroot) {
                return;
            } 
            else {
                if (rank[xroot] < rank[yroot])
                    parent[xroot] = yroot;
                else if (rank[xroot] > rank[yroot])
                    parent[yroot] = xroot;
                else {
                    parent[yroot] = xroot;
                    rank[xroot]++;
                }
            }
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU dsu(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (dsu.find(u) == dsu.find(v)) {
                return {u , v};
            }
            else{
                dsu.unionSets(u, v);
            }
        }
        return {};
    }
};