class Solution {
public:
    int bitwiseComplement(int n) {
        string num = "";

        if (n == 0) return 1;
        
        while (n > 0) {
            num += (n % 2 + '0');
            n /= 2;
        }

        reverse(num.begin(), num.end());

        for (int i = 0; i < num.length(); i++) {
            if (num[i] == '1') {
                num[i] = '0';
            }
            else {
                num[i] = '1';
            }
        }
        
        int m = 0;
        for (int i = 0; i < num.length(); i++) {
            m = m * 2 + (num[i] - '0');
        }

        return m;
    }
};