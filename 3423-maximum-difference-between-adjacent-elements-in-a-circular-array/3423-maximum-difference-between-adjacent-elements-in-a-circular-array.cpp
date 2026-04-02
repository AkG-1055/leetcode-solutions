class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int diff = 0;

        while (i < n) {
            if (i == 0) {
                    diff = max(diff, abs(nums[n - 1] - nums[0]));
                    i++;
            } else {
                    diff = max(diff, abs(nums[i] - nums[i - 1]));
                    i++;
                }
            }
        return diff;
    }
};