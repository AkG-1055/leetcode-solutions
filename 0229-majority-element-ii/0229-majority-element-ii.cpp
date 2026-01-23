class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> mod;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count > n / 3) {
                bool alreadyAdded = false;
                for (int x : mod) {
                    if (x == nums[i]) {
                        alreadyAdded = true;
                        break;
                    }
                }
                if (!alreadyAdded) {
                    mod.push_back(nums[i]);
                }
            }
        }
        return mod;
    }
};