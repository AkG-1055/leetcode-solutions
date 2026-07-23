class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        ans.push_back(words[0]);

        for (int i = 1; i < n ; i++) {
            vector<int> freq_curr(26, 0);
            vector<int> freq_prev(26, 0);

            for (char c: words[i]) {
                freq_curr[c - 'a']++;
            }
            for (char c: ans.back()) {
                freq_prev[c - 'a']++;
            }

            string key_curr;
            for (int count : freq_curr) {
                key_curr += to_string(count);
                key_curr += '#';
            }

            string key_prev;
            for (int count : freq_prev) {
                key_prev += to_string(count);
                key_prev += '#';
            }
            
            if (key_curr != key_prev) ans.push_back(words[i]);
        }

        return ans;;
    }
};