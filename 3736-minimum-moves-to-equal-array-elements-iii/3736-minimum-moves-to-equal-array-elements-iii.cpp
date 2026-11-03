class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            count += (mx - nums[i]);
        }

        return count;
    }
};