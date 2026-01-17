class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int min_price = prices[0];

        for(int i = 0; i < n; i++){
            int profit;

            min_price = min(min_price, prices[i]);
            profit =  prices[i] - min_price;
            
            if (profit >  max_profit){
                max_profit = profit;
            }
        }
        return max_profit;
    }
};