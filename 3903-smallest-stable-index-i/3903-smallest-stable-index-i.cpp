class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int curr_smallest = n;

        for (int i = 0; i < n; i++) {
            int high = *max_element(nums.begin(), nums.begin() + (i + 1));
            int low = *min_element(nums.begin() + i, nums.end());

            int score = high - low;

            if (score <= k) {
                if (i < curr_smallest) {
                    curr_smallest = i;
                }
            }
        }

        if (curr_smallest == n) {
            return -1;
        }
        
        return curr_smallest;
    }
};