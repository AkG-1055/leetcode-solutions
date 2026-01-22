class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};

        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);

        if (lb == nums.end() || *lb != target)
            return {-1, -1};

        int first = lb - nums.begin();
        int last  = ub - nums.begin() - 1;

        return {first, last};
    }
};
