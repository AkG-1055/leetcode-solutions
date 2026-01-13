class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss;
        for (int k = 0; k < nums.size() + 1; k++){
            bool found = false;

            for (int i = 0; i < nums.size(); i++){
                if (k == nums[i]){
                    found = true;
                    break;
                }
            }
        if (!found) return k;
        }
    return -1;
    }
};