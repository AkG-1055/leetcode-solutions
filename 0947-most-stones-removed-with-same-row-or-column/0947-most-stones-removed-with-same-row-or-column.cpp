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
                } 
                else if (rank[rootA] < rank[rootB]) {
                    parent[rootA] = rootB;
                } 
                else {
                    parent[rootB] = rootA;
                    rank[rootA]++;
                }
            }
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU dsu(n);

        int count = 0;

        for (int i = 0; i < stones.size(); i++) {
            for (int j = i + 1; j < stones.size(); j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    dsu.unionSets(i, j);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) {
                count++;
            }
        }
        return stones.size() - count;
    }
};