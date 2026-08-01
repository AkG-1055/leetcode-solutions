class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;

        ans.reserve(ans.size() + nums.size());
        ans.insert(ans.end(), nums.begin(), nums.end());

        return ans;
    }
};