class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;
        int diff = -1;

        for (int i = 0; i < n; i++) {
            if (m.count(nums[i])) {
                diff = i - m[nums[i]];

                if (diff <= k) {
                    return true;
                }
            }
            m[nums[i]] = i;
        }
        return false;
    }
};