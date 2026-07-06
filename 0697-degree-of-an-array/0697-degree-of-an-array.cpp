class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> freq(50000, 0);
        vector<int> first (50000, -1);
        int deg = 0;
        int ans = 0;

        for (int i = 0; i < nums.size() ; i++){
            freq[nums[i]]++;

            if (first[nums[i]] == -1){
                first[nums[i]] = i;
            }

            if (freq[nums[i]] > deg){
                deg = freq[nums[i]];
                ans = i - first[nums[i]] + 1;
            }
            else if (freq[nums[i]] == deg){
                ans = min(ans, i - first[nums[i]] + 1);
            }
        }
        return ans;
    }
};