class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_len = 1;
        int count = 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                count++;
            }
            else{
                count = 1;
            }

            max_len = max(count, max_len);
        }
        count = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
            }
            else{
                count = 1;
            }

            max_len = max(count, max_len);
        }

        return max_len;
    }
};