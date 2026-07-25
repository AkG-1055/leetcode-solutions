class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<bool> taken(numCourses, false);
        for (auto& req : prerequisites) {
            int u = req[0];
            int v = req[1];

            adj[v].push_back(u);

            indegree[req[0]] += 1;
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

            taken[curr] = true;

            for (int neighbour : adj[curr]) {
                indegree[neighbour] -= 1;

                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        for (bool process : taken) {
            if (process == false) {
                return false;
            }
        }
        return true;
    }
};