class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        bool found = false;

        for (int i = 0; i < n; i++){
            if (nums[i] == target){
                found = true;
                return true;
                break;
            }
        }
        while (!found) return false;
        return false; 
    }
};