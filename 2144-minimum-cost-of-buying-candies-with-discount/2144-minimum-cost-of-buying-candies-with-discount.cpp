class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int t_cost = 0;
        int count = 0;
        
        for (int i = n - 1; i >= 0; i--){
            if (count == 2){
                count = 0;
            }
            else{
                t_cost = t_cost + cost[i];
                count++;
            }
        }
        return t_cost;
    }
};