class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51, 0);
        unordered_set<int> seen;

        int left = 0;
        int right = k - 1;

        while (right < nums.size()) {
            for (int i = left; i <= right; i++) {
                if (seen.find(nums[i]) == seen.end()){
                    freq[nums[i]]++;
                    seen.insert(nums[i]);
                }
                else{
                    continue;
                }
            }
            left++;
            right++;
            seen.clear();
        }

        int mx = -1;
        for (int i = 0; i < 51; i++) {
            if (freq[i] == 1) {
                mx = max(mx, i);
            }
        }

        return mx;
    }
};