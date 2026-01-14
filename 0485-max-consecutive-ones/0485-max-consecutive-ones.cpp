class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int max_count = 0;

        for (int i = 0; i < n; i++){
            if (nums[i] == 1){
                count = count + 1;
                if (count > max_count){
                    max_count = count;
                }
            }
            else{
                count = 0;
            }
        }
        return max_count;
    }
};