class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> ans;
        vector<int> outdegree(n, 0);
        queue<int> q;

        for (int i = 0; i < graph.size(); i++) {
            for (int near : graph[i]) {
                reverseGraph[near].push_back(i);
                outdegree[i] += 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for (int& prev : reverseGraph[curr]) {
                outdegree[prev] -= 1;

                if (outdegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};