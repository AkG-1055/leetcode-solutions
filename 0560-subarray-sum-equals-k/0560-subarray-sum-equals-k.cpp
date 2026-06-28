class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> mpp;
        mpp[0] = 1;
        int PreSum = 0; int count = 0;

        for (int i = 0; i < nums.size(); i++){
            PreSum += nums[i];
            int remove = PreSum - k;
            count += mpp[remove];
            mpp[PreSum] += 1;
        }

        return count;
    }
};