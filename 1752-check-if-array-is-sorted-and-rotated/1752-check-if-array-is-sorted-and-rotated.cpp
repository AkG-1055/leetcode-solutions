class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int error_count = 0;

        for(int i = 0; i < n; i++){
            if (nums[i] > nums[(i+1) % n]){
                error_count++;
            }
        }
        if (error_count >= 2) return false;
        if (error_count <= 1) return true;
        return 0;
    }
};