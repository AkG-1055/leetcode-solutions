class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        int i = 1;
        
        if (n == 1) return nums[0];

        while (i < n - 1){
            if (nums[i] != nums [i - 1] && nums[i] != nums[i + 1]){
                sum = sum + nums[i];
            }
            i++;
        }
        if (nums[0] != nums[1]){
            sum = sum + nums[0];
        }
        if (nums[n - 1] != nums[n - 2]){
            sum = sum + nums[n - 1];
        }
        return sum;
    }
};