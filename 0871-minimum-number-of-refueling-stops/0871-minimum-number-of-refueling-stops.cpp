class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int curr = startFuel;
        int count = 0;

        if (curr == target) return 0;

        int i = 0;
        while (curr < target) {
            while (i < stations.size() && stations[i][0] <= curr) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty()) {
                return -1;
            }
            else{
                int fuel = pq.top();
                pq.pop();
                curr += fuel;
                count++;
            }
        }

        return count;
    }
};