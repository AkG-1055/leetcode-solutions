class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int B = 0;
        int E = n - 1;

        while (B < E){
            int mid = (B + E)/2;

            if (mid % 2 == 1){
                mid--;
            }
            if (nums[mid] == nums[mid + 1]){
                B = mid + 2;
            }
            else{
                E = mid;
            }
        }
        return nums[B];
    }
};