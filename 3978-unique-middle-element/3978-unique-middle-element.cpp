class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = (n - 1) / 2;
        if (n == 1){
            return true;
        }

        for (int i = 0; i < n; i++){
            if (i != mid && nums[i] == nums[mid]){
                return false;
            }
        }
        return true;
    }
};