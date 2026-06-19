class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> peaks;
        peaks.push_back(0);

        for (int i = 0; i < n; i++){
            int curr = gain[i] + peaks[i];
            peaks.push_back(curr);
        }

        int highest = *max_element(peaks.begin(), peaks.end());
        return highest;
    }
};