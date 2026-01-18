class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> mod(n);    
        int pos = 0;
        int neg = 1;

        for(int i = 0; i < n; i++){
            if (nums[i] > 0){
                mod[pos] = nums[i];
                pos = pos + 2;
            }
            else{
                mod[neg] = nums[i];
                neg = neg + 2;
            }
        }
        return mod;
    }
};