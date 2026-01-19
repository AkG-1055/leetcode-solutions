class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int max_count = 0;
        int i, j;

        for (i = 0; i < n; i++){
            int count = 1;
            for(j = i + 1; j < n; j++){
                if (nums[i] == nums[j]){
                    count = count + 1;
                }
            }
            if (count > max_count){
                max_count = count;
            }
            if (max_count > n/2){
                return nums[i];
            }
        }    
        return nums[0];
    }
};