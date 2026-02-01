class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int hours;

        int max = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = max;
        int mid;

        while (low <= high) {
            mid = (high + low) / 2;
            long long sum = 0;

            for (int j = 0; j < n; j++) {
                hours = (piles[j] + mid - 1) / mid;
                sum = sum + hours;
            }
            if (sum <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};