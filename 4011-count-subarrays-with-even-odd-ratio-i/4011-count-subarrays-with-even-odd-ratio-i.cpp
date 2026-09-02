class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int count = 0;

        for (int left = 0; left < nums.size(); left++) {
            int x = 0, y = 0;
            for (int right = left; right < nums.size(); right++) {
                if (nums[right] % 2 != 0) {
                    y++;
                } 
                else {
                    x++;
                }
                
                if (y > 0 && b * x <= a * y) {
                    count++;
                }
            }
        }

        return count;
    }
};