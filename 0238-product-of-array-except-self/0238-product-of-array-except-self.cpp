class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1;
        int right = 1;
        vector<int> lm; lm.push_back(1);
        vector<int> rm; rm.push_back(1);
        vector<int> ans;

        for (int i = 1; i < nums.size(); i++){
            left = left * nums[i - 1];
            lm.push_back(left);
        }

        for (int i = nums.size() - 2; i >= 0; i--){
            right = right * nums[i + 1];
            rm.push_back(right);
        }

        for (int i = 0; i < nums.size(); i++){
            int mul = lm[i] * rm[nums.size() - i - 1];
            ans.push_back(mul);
        }
        return ans;
    }
};