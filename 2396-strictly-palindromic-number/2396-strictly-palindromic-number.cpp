class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left <= right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            }
            else{
                return false;
            }
        }

        return true;
    }

    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i < n - 1; i++) {
            int curr = n;
            string s = "";
            
            while (curr > 0) {
                s.push_back(curr % i + '0');
                curr /= i;
            }

            if(!isPalindrome(s)) return false;
        }
        return true;
    }
};