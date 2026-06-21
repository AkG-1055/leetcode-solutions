class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> duplicate;

        for (int i = 0; i < m; i++) {
            duplicate.push_back(nums1[i]);
        }

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < duplicate.size() && j < nums2.size()) {
            if (duplicate[i] <= nums2[j]) {
                nums1[k++] = duplicate[i++];
            } else {
                nums1[k++] = nums2[j++];
            }
        }

        while (i < duplicate.size()) {
            nums1[k++] = duplicate[i++];
        }

        while (j < nums2.size()) {
            nums1[k++] = nums2[j++];
        }
    }
};