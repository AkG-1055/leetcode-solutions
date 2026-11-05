class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr2[j] - arr1[i]) <= d) {
                    count++;
                    break;
                }
            }
        }
        return n - count;
    }
};