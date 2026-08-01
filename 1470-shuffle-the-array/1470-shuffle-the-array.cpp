class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int right = n;

        for (int left = 0; left < n; left++) {
            ans.push_back(nums[left]);
            ans.push_back(nums[right]);
            right++;
        }

        return ans;
    }
};