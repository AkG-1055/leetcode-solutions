class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> ans;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int d = (x * x) + (y * y);
            pq.push({d, {x, y}});
        }

        while (k > 0) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
            k--;
        }

        return ans;
    }
};