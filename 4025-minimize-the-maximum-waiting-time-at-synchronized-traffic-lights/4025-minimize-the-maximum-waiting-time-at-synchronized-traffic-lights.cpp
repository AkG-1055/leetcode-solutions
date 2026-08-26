class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        sort(lights.begin(), lights.end());
        int pen = 0;

        for (int i = 0; i < arrivalTime.size(); i++) {
            int r = arrivalTime[i] % period;
            int waiting = 0;
            
            if (r >= lights[lights.size() - 1]) {
                waiting = period - r;
            }

            pen = max(pen, waiting);
        }
        return pen;
    }
};