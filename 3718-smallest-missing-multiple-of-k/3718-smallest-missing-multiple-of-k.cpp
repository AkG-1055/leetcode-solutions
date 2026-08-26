class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> freq(101, 0);
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        int i = k;
        while (true) {
            if (i <= 100 && freq[i] == 0) {
                return i;
            }
            
            if (i > 100) {
                return i;
            }

            i += k;
        }

        return -1;
    }
};