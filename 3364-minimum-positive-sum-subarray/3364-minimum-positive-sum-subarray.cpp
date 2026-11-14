class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int min_sum = INT_MAX;

        while (l <= r) {
            int left = 0;
            int right = left + l - 1;
            int sum = 0;

            for (int i = left; i <= right; i++) {
                sum += nums[i];
            }

            if (sum > 0) {
                min_sum = min(min_sum, sum);
            }

            right++;

            while (right < nums.size()) {
                sum += nums[right] - nums[left];

                if (sum > 0) {
                    min_sum = min(min_sum, sum);
                }

                right++;
                left++;
            }
            l++;
        }
        
        if (min_sum == INT_MAX) return -1;

        return min_sum;
    }
};