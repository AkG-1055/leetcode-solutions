class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;

        for (auto& account : accounts) {
            int wealth = accumulate(account.begin(), account.end(), 0);
            if (wealth >= max_wealth) {
                max_wealth = wealth;
            }
        }

        return max_wealth;
    }
};