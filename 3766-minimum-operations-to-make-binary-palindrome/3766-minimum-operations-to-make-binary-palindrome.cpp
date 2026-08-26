class Solution {
public:
    bool isPalindrome(int num) {
        string s = "";
        while (num > 0) {
            s.push_back(num % 2 + '0');
            num /= 2;
        }

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int moves = 0;

            while (true) {
                if (x - moves > 0 && isPalindrome(x - moves)) {
                    ans.push_back(moves);
                    break;
                }

                if (isPalindrome(x + moves)) {
                    ans.push_back(moves);
                    break;
                }
                moves++;
            }
        }
        return ans;
    }
};