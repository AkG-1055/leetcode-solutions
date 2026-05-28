class Solution {
public:
    void findCombinations(vector<int>& nums, int index, int k, vector<vector<int>>& res, vector<int>& ds) {
        if (ds.size() == k) {
            res.push_back(ds);
            return;
        }

        if (index == nums.size()){
            return;
        }

        ds.push_back(nums[index]);
        findCombinations(nums, index + 1, k, res, ds);
        ds.pop_back();

        findCombinations(nums, index + 1, k, res, ds);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            nums.push_back(i + 1);
        }

        vector<vector<int>> res;
        vector<int> ds;
        findCombinations(nums, 0, k, res, ds);
        return res;
    }
};