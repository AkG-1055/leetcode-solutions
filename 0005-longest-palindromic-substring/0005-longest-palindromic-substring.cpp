class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp (n, vector<int>(n, false));
        int start = 0;
        int maxLen = 1;

        for (int len = 1; len <= n; len++){
            for (int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;

                if (len == 1){
                    dp[i][j] = true;
                }
                else if (len == 2){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }
                
                if (dp[i][j] && len > maxLen){
                    start = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};