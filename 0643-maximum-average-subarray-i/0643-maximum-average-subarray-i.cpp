class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = left + k - 1;
        int max_sum = INT_MIN;
        int sum = 0;

        for (int i = left; i <= right; i++) {
            sum += nums[i];
        }

        max_sum = max(max_sum, sum);

        right++;

        while (right < nums.size()) {
            sum += (nums[right] - nums[left]);
            max_sum = max(max_sum, sum);
            right++;
            left++;
        }

        double ans = (double)max_sum / k;

        return ans;
    }
};