class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max = nums[0];
        int curr_min = nums[0];
        int mx = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int temp_max = max({x, curr_max * x, curr_min * x});
            int temp_min = min({x, curr_max * x, curr_min * x});

            curr_max = temp_max;
            curr_min = temp_min;

            mx = max(curr_max, mx);
        }

        return mx;
    }
};