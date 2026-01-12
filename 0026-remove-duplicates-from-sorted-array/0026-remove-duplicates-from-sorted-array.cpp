class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int reader = 1;
        int writer = 0;

        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i-1]){
                writer++;
                nums[writer] = nums[i];
            }
        }

        return writer + 1;
    }
};