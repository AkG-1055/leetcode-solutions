class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        vector<string> ans(score.size(), "0");

        for (int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }
        
        int k = 1;
        while(!pq.empty()) {
            int index = pq.top().second;
            if (k == 1) {
                ans[index] = "Gold Medal";
            }
            else if (k == 2) {
                ans[index] = "Silver Medal";
            }
            else if (k == 3) {
                ans[index] = "Bronze Medal";
            }
            else{
                ans[index] = to_string(k);
            }
            pq.pop();
            k++;
        }
        return ans;
    }
};