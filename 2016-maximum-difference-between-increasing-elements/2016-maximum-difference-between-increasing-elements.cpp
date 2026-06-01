class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int max = -1;

        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int diff = -1;
                if (nums[j] > nums[i]){
                    diff = nums[j] - nums[i];
                }
                if (diff > max){
                    max = diff;
                }
            }
        }
        return max;
    }
};