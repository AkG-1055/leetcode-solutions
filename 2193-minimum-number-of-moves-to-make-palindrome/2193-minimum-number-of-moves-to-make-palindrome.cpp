class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int moves = 0;
        int right = s.length() - 1;
        int left = 0;
        
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            }
            else{
                int i = right;

                while (i > left && s[i] != s[left]) {
                    i--;
                }

                if (i == left) {
                    swap(s[left], s[left + 1]);
                    moves++;
                }
                else{
                    while (i < right) {
                        swap(s[i], s[i + 1]);
                        i++;
                        moves++;
                    }
                    left++;
                    right--;
                }
            }
        }
        return moves;
    }
};