class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> output;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - i - 1; j++){
                if (nums[j] > nums[j+1]){
                    swap(nums[j] , nums[j+1]);
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (nums[i] == target){
                output.push_back(i);
            }
        }
        return output;
    }
};