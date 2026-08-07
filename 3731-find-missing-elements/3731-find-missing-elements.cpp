class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        vector<int> freq(mx + 1, 0);
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for (int i = mn; i <= mx; i++) {
            if (freq[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};