class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            int u = points[i][0];
            int v = points[i][1];

            if (u == x || v == y) {
                int d = abs(u - x) + abs(v - y);
                pq.push({d, i});
            }
            else{
                continue;
            }
        }

        if (pq.size() != 0) {
            return pq.top().second;
        }
        else{
            return -1;
        }
    }
};