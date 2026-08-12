class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                double frac = (double)arr[i] / arr[j];

                if (pq.size() < k) {
                    pq.push({frac, {arr[i] ,arr[j]}});
                }
                else{
                    if (frac < pq.top().first) {
                        pq.pop();
                        pq.push({frac, {arr[i] ,arr[j]}});
                    }
                    else{
                        continue;
                    }
                }
            }
        }

        return {pq.top().second.first, pq.top().second.second};
    }
};