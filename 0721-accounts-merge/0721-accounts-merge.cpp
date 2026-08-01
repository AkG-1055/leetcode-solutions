class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> rank;

        DSU (int n) {
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
            }
            else{
                if (rank[rootA] > rank[rootB]) {
                    parent[rootB] = rootA;
                }
                else if (rank[rootA] < rank[rootB]) {
                    parent[rootA] = rootB;
                }
                else{
                    parent[rootB] = rootA;
                    rank[rootA]++;
                }
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu(accounts.size());

        unordered_map<string, int> emailOwner;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (!emailOwner.count(accounts[i][j])) {
                    emailOwner[accounts[i][j]] = i;
                }
                else{
                    dsu.unionSets(i, emailOwner[accounts[i][j]]);
                }
            }
        }

        unordered_map<int, set<string>> groups;
        for (int i = 0; i < accounts.size(); i++) {
            int root = dsu.find(i);

            for (int j = 1; j < accounts[i].size(); j++) {
                groups[root].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> ans;

        for (auto& group : groups) {
            int root = group.first;

            vector<string> account;
            account.push_back(accounts[root][0]);

            for (string email : group.second) {
                account.push_back(email);
            }
            ans.push_back(account);
        }

        return ans;
    }
};