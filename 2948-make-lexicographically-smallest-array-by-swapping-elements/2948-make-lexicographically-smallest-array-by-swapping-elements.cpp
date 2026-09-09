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

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first <= limit) {
                dsu.unionSets(arr[i].second, arr[i - 1].second);
            }
        }

        unordered_map<int, vector<int>> indices;
        unordered_map<int, vector<int>> values;
        for (auto& p : arr) {
            int idx = p.second;
            int value = p.first;
            int root = dsu.find(p.second);

            indices[root].push_back(idx);
            values[root].push_back(value);
        }

        for (auto&[root, idx] : indices) {
            sort(idx.begin(), idx.end());
            sort(values[root].begin(), values[root].end());

            for (int i = 0; i < idx.size(); i++) {
                nums[idx[i]] = values[root][i];
            }
        }

        return nums;
    }
};