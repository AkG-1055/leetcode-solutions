class Solution {
public:
    void backtrack (vector<int>& nums, int start, vector<vector<int>>& res){
        if (start == nums.size()){
            res.push_back(nums);
            return;
        }

        unordered_set<int> seen;

        for (int i = start; i < nums.size(); i++){
            if (seen.count(nums[i])){
                continue;
            }

            seen.insert(nums[i]);

            swap (nums[start], nums[i]);
            backtrack (nums, start + 1, res);
            swap (nums[start], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack (nums, 0, res);
        return res;
    }
};