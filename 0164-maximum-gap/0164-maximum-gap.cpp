class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int max = -1;
        int n = nums.size();

        if (n < 2)
            return 0;

        int max_val = *max_element(nums.begin(), nums.end());

        for (long long exp = 1; max_val / exp > 0; exp *= 10) {
            vector<vector<int>> buckets(10);

            for (int num : nums)
                buckets[(num / exp) % 10].push_back(num);

            int i = 0;
            for (auto& bucket : buckets)
                for (int num : bucket)
                    nums[i++] = num;
        }

        for (int i = 0; i < n - 1; i++) {
            int diff = 0;

            diff = nums[i + 1] - nums[i];
            if (diff > max) {
                max = diff;
            }
        }
        return max;
    }
};
