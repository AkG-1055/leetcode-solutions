class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
         vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<set<int>> prereq(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<bool> ans;
        queue<int> q;

        for (auto& pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];

            adj[u].push_back(v);

            indegree[v]++;
        }

        for (int course = 0; course < numCourses; course++) {
            if (indegree[course] == 0) {
                q.push(course);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto& near : adj[curr]) {
                for (int p : prereq[curr]) {
                    prereq[near].insert(p);
                }
                prereq[near].insert(curr);

                indegree[near]--;

                if (indegree[near] == 0) {
                    q.push(near);
                }
            }
        }

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            ans.push_back(prereq[v].count(u));
        }

        return ans;
    }
};