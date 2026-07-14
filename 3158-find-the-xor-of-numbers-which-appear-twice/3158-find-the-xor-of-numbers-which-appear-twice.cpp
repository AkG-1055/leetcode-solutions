class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]){
                result = result ^ nums[i];
            }
        }
        return result;
    }
};