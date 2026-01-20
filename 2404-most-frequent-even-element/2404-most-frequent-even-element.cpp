class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        int bestVal = -1;
        int bestFreq = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) continue;

            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }

            if (count > bestFreq ||
               (count == bestFreq && nums[i] < bestVal)) {
                bestFreq = count;
                bestVal = nums[i];
            }
        }

        return bestVal;
    }
};
