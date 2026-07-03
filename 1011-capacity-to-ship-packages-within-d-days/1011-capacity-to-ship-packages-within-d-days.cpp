class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int daysUsed = 1;
        int currWeight = 0;
        for (int w : weights){
            if (currWeight + w <= capacity){
                currWeight += w; 
            }
            else{
                daysUsed++;
                currWeight = w;
            }
        }
        return daysUsed <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high){
            int mid = (low + high) / 2;
            if (canShip(weights, days, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};