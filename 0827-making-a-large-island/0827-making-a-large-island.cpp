class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> rank;
        vector<int> size;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            size.resize(n, 1);

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
                    size[rootA] += size[rootB];
                } else if (rank[rootA] < rank[rootB]) {
                    parent[rootA] = rootB;
                    size[rootB] += size[rootA];
                } else {
                    parent[rootB] = rootA;
                    rank[rootA]++;
                    size[rootA] += size[rootB];
                }
            }
        }
    };

    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int node = row * n + col;
                        int adj_node = newr * n + newc;
                        dsu.unionSets(node, adj_node);
                    }
                }
            }
        }

        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;
                set<int> components;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        components.insert(dsu.find(newr * n + newc));
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += dsu.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, dsu.size[dsu.find(cellNo)]);
        }

        return mx;
    }
};