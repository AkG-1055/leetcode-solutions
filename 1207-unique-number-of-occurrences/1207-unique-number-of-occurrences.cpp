class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2001, 0);

        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i] + 1000]++;
        }

        vector<int> ans;
        for (int f : freq) {
            if (f > 0) {
                ans.push_back(f);
            }
        }
        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] == ans[i + 1]) {
                return false;
            }
        }

        return true;
    }
};