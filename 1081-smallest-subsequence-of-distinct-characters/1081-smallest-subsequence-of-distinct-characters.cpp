class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastOccurence(26);
        vector<bool> visited(26, false);

        for (int i = 0; i < s.length(); i++) {
            lastOccurence[s[i] - 'a'] = i;
        }

        string ans;

        for (int i = 0; i < s.length(); i++) {
            if (visited[s[i] - 'a']) {
                continue;
            }

            while (!ans.empty() && ans.back() > s[i] && lastOccurence[ans.back() - 'a'] > i) {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            visited[s[i] - 'a'] = true;
        }

        return ans;
    }
};