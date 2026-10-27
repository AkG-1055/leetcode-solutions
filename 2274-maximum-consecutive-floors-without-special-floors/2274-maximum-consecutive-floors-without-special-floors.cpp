class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int n = special.size();
        int diff = special[0] - bottom;

        for (int i = 1; i < n; i++) {
            diff = max(diff, (special[i] - special[i - 1]) - 1);
        }

        diff = max(diff, (top - special[n - 1]));
        return diff;
    }
};