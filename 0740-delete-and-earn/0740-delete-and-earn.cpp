class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> points(10001, 0);

        for (int i : nums){
            points[i] += i;
        }

        int n = points.size();

        vector<int> dp (n + 1);
        dp[0] = points[0];
        dp[1] = points[1];

        for (int i = 2; i < n; i++){
            dp[i] = max (dp[i - 1], points[i] + dp[i - 2]);
        }

        return max(dp[n - 1], dp[n - 2]);
    }
};