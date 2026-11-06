class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int h = 0;

        for (int i = 0; i < n; i++) {
            int count = n - i;

            if (citations[i] >= count && count >= h) {
                h = count;
            }
        }

        return h;
    }
};