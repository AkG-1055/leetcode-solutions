class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]  + 1) {
                sum += nums[i];
            }
            else{
                break;
            }
        }

        vector<int> freq(51, 0);

        for (int i : nums) {
            freq[i]++;
        }

        if (sum > 50) return sum;

        for (int i = sum; i <= 50; i++) {
            if (i >= sum && freq[i] == 0) {
                return i;
            }
        }

        return 51;
    }
};