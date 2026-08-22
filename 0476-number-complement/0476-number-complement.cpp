class Solution {
public:
    int findComplement(int num) {
        string binary = "";

        while (num > 0) {
            binary.push_back(num % 2 + '0');
            num /= 2;
        }

        reverse(binary.begin(), binary.end());

        for (int i = 0; i < binary.length(); i++) {
            if (binary[i] == '0') {
                binary[i] = '1';
            }
            else{
                binary[i] = '0';
            }
        }

        int n = 0;
        for (char ch : binary) {
            n = n * 2 + (ch - '0');
        }

        return n;
    }
};