class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++) {
            vector<int> freq(26, 0);
            string word = strs[i];
            for (char c : word) {
                freq[c - 'a']++;
            }

            string key;

            for (int count : freq) {
                key += to_string(count);
                key += '#';
            }

            mp[key].push_back(word);
        }

        for (auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};