class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> ind;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                ind.push_back(i);
            }
            else if (s[i] == ')') {
                int left = ind[ind.size() - 1];
                reverse(s.begin() + left, s.begin() + i);
                ind.pop_back();
            }
        }
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == ')') {
                continue;
            }
            else{
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};