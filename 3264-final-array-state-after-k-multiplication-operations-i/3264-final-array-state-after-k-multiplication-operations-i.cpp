class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while (k > 0) {
            auto min_ptr = min_element(nums.begin(), nums.end());
            int min_idx = min_ptr - nums.begin();
            int element = *min_element(nums.begin(), nums.end());
            nums[min_idx] = (element * multiplier);
            k--;
        }
        return nums;
    }
};