class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            prefixGcd.push_back(gcd(nums[i], mx));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;
        int n = prefixGcd.size();
        for (int i = 0; i < n; i++) {
            if (i < n - 1 - i){
                long long ans = gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
                sum += ans;
            }
            else{
                break;
            }
        }

        return sum;
    }
};