class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        int k = 1;

        while (n > 0) {
            if (n - k >= 0) {
                count++;
                n -= k;
                k++;
            }
            else{
                break;
            }
        }

        return count;
    }
};