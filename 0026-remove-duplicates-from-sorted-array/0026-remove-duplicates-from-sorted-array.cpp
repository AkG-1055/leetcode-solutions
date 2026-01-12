class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int reader = 1;
        int writer = 0;

        for (int reader = 1; reader < nums.size(); reader++){
            if (nums[reader] != nums[writer]){
                writer++;
                nums[writer] = nums[reader];
            }
        }

        return writer + 1;
    }
};