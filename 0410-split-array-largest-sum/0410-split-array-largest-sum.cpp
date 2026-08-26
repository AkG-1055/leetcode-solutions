class Solution {
public:
    int CountK(vector<int>& arr, int mid) {
        int elements = 1;
        long long SubArray = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (SubArray + arr[i] <= mid) {
                SubArray += arr[i];
            }
            else{
                elements += 1;
                SubArray = arr[i];
            }
        }
        return elements;
    }

    int findSubArray(vector<int>& arr, int n, int m) {
        if (m > n) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high) {
            int mid = (low + high) / 2;
            int elements = CountK(arr, mid);
            if (elements > m) {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }

    int splitArray(vector<int>& nums, int k) {
        return findSubArray(nums, nums.size(), k);
    }
};