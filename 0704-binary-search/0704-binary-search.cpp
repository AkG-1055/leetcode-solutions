class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int B, M, E;
        B = 0;
        E = n - 1;

        while (B <= E){
            M = (B + E)/2;

            if (nums[M] == target){
                return M;
            }
            else if (nums[M] < target){
                B = M + 1;
            }
            else{
                E = M - 1;
            }
        }
        return -1;
    }
};