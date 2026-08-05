class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans = "";
        for (int i = s.length() - 1; i >= 0; i--){
            if (s[i] != ' ') {
                ans.push_back(s[i]);
            }
            else if (s[i] == ' ' && ans.length() == 0){
                continue;
            }
            else{
                break;
            }
        }
        return ans.length();
    }
};