class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        bool found = false;

        for (int i = 0; i < n; i++){
            if (nums[i] == target){
                found = true;
                return i;
            }
        }
        if (!found){
            int i;
            int max_min = 0;
            for (i = 0; i < n; i++){
                if (nums[i] < target){
                    max_min = max_min + 1;
                }
            }
            return max_min;
        }
        return -1;
    }
};