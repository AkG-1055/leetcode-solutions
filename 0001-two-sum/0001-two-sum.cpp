class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i, j, sum;

        for (i = 0; i < n; i++){
            for (j = i + 1; j < n; j++){
                sum = nums[i] + nums[j];

                if (target == sum){
                    return {i, j};
                }
            }
        }
        return {};
    }
};