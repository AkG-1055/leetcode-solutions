class Solution {
public:
    bool isValid(vector<int>& nums, int capability, int k){
        int i = 0;
        int count = 0;

        while (i < nums.size()){
            if (nums[i] <= capability){
                i = i + 2;
                count = count + 1;
            }
            else{
                i = i + 1;
            }
            if (count >= k){
                return true;
            }
        }
        return false;;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        
        while (l < r){
            int m = l + (r - l) / 2;

            if (isValid(nums, m, k)){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};