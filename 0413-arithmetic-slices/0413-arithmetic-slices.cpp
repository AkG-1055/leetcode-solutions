class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        if (n < 3) return 0;

        for (int left = 0; left < nums.size() - 2; left++) {
            int diff = nums[left + 1] - nums[left];
            for(int right = left + 1; right < nums.size(); right++) {
                if (nums[right] - nums[right - 1] == diff) {
                    if (right - left + 1 >= 3) {
                        count++;
                    }
                    else{
                        continue;
                    }
                }
                else{
                    break;
                }
            }
        }

        return count;
    }
};