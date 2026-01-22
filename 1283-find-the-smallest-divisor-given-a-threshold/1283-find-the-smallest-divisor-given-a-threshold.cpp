class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int L = 1;
        int R = *max_element(nums.begin(), nums.end());
        int ans = R;

        while (L <= R) {
            int mid = (L + R) / 2;
            long long sum = 0;

            for (int x : nums) {
                sum += (x + mid - 1) / mid;
            }

            if (sum <= threshold) {
                ans = mid;       
                R = mid - 1;
            } 
            else {
                L = mid + 1;
            }
        }

        return ans;
    }
};
