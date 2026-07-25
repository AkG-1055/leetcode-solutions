class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;

        while (n > 0) {
            int curr = n % 10;
            digits.push_back(curr);
            n = n / 10;
        }

        sort(digits.rbegin(), digits.rend());

        return (digits[0] * digits[1]);
    }
};