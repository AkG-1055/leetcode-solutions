class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n, INT_MIN);
        mini[n - 1] = nums[n - 1];
        int curr_max = nums[0];

        for (int i = n - 2; i >= 0; i--) {
            int curr_min = min(mini[i + 1], nums[i]);
            mini[i] = curr_min;
        }

        for (int i = 0; i < n; i++) {
            curr_max = max(curr_max, nums[i]);
            int score = curr_max - mini[i];

            if (score <= k) {
                return i;
            }
        }

        return -1;
    }
};