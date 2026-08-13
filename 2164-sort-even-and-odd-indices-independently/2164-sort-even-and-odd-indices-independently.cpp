class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                even.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
        }

        sort(odd.rbegin(), odd.rend());
        sort(even.begin(), even.end());

        int k = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = even[k];
                k++;
            }
            else{
                nums[i] = odd[j];
                j++;
            }
        }

        return nums;
    }
};