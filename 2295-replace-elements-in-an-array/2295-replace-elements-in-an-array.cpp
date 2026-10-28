class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        for (auto op : operations) {
            int from = op[0];
            int to = op[1];

            int ind = mp[from];

            nums[ind] = to;
            mp.erase(from);
            mp[to] = ind;
        }

        return nums;
    }
};