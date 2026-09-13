class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mn = -1;
        int mx = -1;
        int bad = -1;

        long long count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                bad = i;
            }
            if (nums[i] == minK) {
                mn = i;
            }
            if (nums[i] == maxK) {
                mx = i;
            }

            if (mn != -1 && mx != -1) {
                count += max(0, min(mn, mx) - bad);
            }
        }

        return count;
    }
};