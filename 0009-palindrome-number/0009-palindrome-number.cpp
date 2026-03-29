class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        int digit = 0;
        int rev = 0;

        if (x < 0){
            return false;
        }

        while (x != 0){
            digit = x % 10;
            
            if (rev > INT_MAX / 10 || rev == INT_MAX / 10 && digit > 7) return false;
            if (rev < INT_MIN / 10 || rev == INT_MIN / 10 && digit < -8) return false;

            rev = rev * 10 + digit;
            x = x / 10;
        }

        if (rev == original){
            return true;
        }

        return false;
    }
};