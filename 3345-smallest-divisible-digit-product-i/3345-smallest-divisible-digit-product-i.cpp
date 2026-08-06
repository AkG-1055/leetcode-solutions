class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; i < INT_MAX; i++) {
            int product = 1;
            int curr = i;

            while (curr >= 1) {
                int digit = curr % 10;
                product *= digit;
                curr = curr / 10;
            }

            if (product % t == 0) {
                return i;
                break;
            }
        }

        return -1;
    }
};