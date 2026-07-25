class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> order;

        for (auto& req : prerequisites) {
            int u = req[0];
            int v = req[1];
            adj[v].push_back(u);

            indegree[u] += 1;
        }

        queue<int> q;

        for (int course = 0; course < numCourses; course++) {
            if (indegree[course] == 0) {
                q.push(course);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for (int near : adj[curr]) {
                indegree[near] -= 1;

                if (indegree[near] == 0) {
                    q.push(near);
                }
            }
        }
        
        if (order.size() == numCourses) {
            return order;
        }
        else{
            return {};
        }
    }
};