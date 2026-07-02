class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n);

        dp[0] = true;

        for (int i = 0; i <= n; i++){
            for (string &word : wordDict){
                if (i >= word.length()){
                    if (dp[i - word.length()] && s.substr(i - word.length(), word.length()) == word){
                        dp[i] = true;
                    }
                }
            }
        }

        return dp[n];
    }
};