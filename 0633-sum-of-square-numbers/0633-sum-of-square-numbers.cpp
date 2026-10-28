class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0;
        int b = sqrt(c);

        while (a <= b) {
            long long sum = 1LL * a * a + 1LL * b * b;

            if (sum < c) {
                a++;
            }
            else if (sum > c) {
                b--;
            }
            else{
                return true;
            }
        }

        return false;
    }
};