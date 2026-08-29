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

            if (rootA == rootB) {
                return;
            } else {
                if (rank[rootA] > rank[rootB]) {
                    parent[rootB] = rootA;
                } else if (rank[rootA] < rank[rootB]) {
                    parent[rootA] = rootB;
                } else {
                    parent[rootB] = rootA;
                    rank[rootA]++;
                }
            }
        }
    };

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        DSU dsu(n);
        vector<vector<char>> components(n);

        for (auto& pair : pairs) {
            int u = pair[0];
            int v = pair[1];

            if (dsu.find(u) != dsu.find(v)) {
                dsu.unionSets(u, v);
            }
        }

        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            components[root].push_back(s[i]);
        }

        int m = components.size();

        for (int i = 0; i < m; i++) {
            sort(components[i].begin(), components[i].end());
        }

        vector<int> index(n, 0);
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);

            s[i] = components[root][index[root]];
            index[root]++;
        }

        return s;
    }
};