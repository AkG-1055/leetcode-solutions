class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int left = 0;
        int right = left + k - 1;
        int sum = 0;

        for (int i = left; i <= right; i++){
            sum += arr[i];
        }
        right++;

        double avg = (double)sum / k;
        if (avg >= threshold) count++;

        while (right < arr.size()) {
            sum += arr[right] - arr[left];
            avg = (double)sum / k;

            if (avg >= threshold) count++;

            right++;
            left++;
        }

        return count;
    }
};