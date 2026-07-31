class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        void unionSets(int a, int b) {
            int rootA = find(a);
            int rootB = find(b);

            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            }
            else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            }
            else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int count = 0;

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            if (dsu.find(u) == dsu.find(v)) {
                count++;
            }
            else{
                dsu.unionSets(u, v);
            }
        }
        
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) {
                components++;
            }
        }

        if (count >= components - 1) {
            return components - 1;
        }

        return -1;
    }
};