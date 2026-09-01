class Solution {
public:
    string reverseWords(string s) {
        string ans= "";
        vector<string> words;
        string curr = "";

        for (int right = 0; right < s.length(); right++) {
            if (isalnum(s[right])) {
                curr.push_back(s[right]);
            }
            else{
                words.push_back(curr);
                curr.clear();
            }
        }

        if (!curr.empty()) {
            words.push_back(curr);
        }

        int n = words.size();
        for (int i = n - 1; i >= 1; i--) {
            if (!words[i].empty()) {
                ans += words[i];
                ans.push_back(' ');
            }
        }

        if (!words[0].empty()) {
            ans += words[0];
        }
        else{
            ans.pop_back();
        }

        return ans;
    }
};