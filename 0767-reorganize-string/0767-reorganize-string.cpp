class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        vector<pair<int, char>> curr;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                curr.push_back({freq[i], i + 'a'});
            }
        }

        string ans = "";

        while (ans.length() < s.length()) {
            sort(curr.rbegin(), curr.rend());

            if (ans.empty() || curr[0].second != ans.back()) {
                ans.push_back(curr[0].second);
                curr[0].first -= 1;
            }
            else{
                if (curr.size() == 1 || curr[1].first == 0) {
                    return "";
                }

                ans.push_back(curr[1].second);
                curr[1].first -= 1;
            }
        }

        return ans;
    }
};