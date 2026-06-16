class Solution {
public:
    void findSubsets(int index, vector<int>& nums, vector<vector<int>>& res,
                     vector<int>& ds) {
        if (index == nums.size()) {
            res.push_back(ds);
            return;
        }

        ds.push_back(nums[index]);
        findSubsets(index + 1, nums, res, ds);
        ds.pop_back();

        while (index + 1 < nums.size() && nums[index] == nums[index + 1]){
            index++;
        }

        findSubsets(index + 1, nums, res, ds);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, res, ds);
        return res;
    }
};