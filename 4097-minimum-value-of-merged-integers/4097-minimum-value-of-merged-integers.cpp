class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        vector<int> array;
        int i = 0;

        while (i < n - 1) {
            string first = to_string(nums[i]);
            string second = to_string(nums[i + 1]);
            string number = first + second;

            int num = stoi(number);
            array.push_back(num);

            i += 2;
        }
        
        int mn = *min_element(array.begin(), array.end());
        return mn;
    }
};