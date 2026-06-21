class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                res.push_back(tolower(s[i]));
            }
        }

        int n = res.length();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            if (res[left] == res[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};