class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= 3; j++) {
                if (i + j <= n) {
                    int jumpCost = costs[i + j - 1] + j * j;
                    dp[i] = min(dp[i], jumpCost + dp[i + j]);
                }
            }
        }
        return dp[0];
    }
};