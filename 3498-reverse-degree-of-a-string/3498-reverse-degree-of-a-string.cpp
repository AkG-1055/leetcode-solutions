class Solution {
public:
    int reverseDegree(string s) {
        int deg = 0;

        for (int i = 0; i < s.length(); i++) {
            int ind = 26 - (s[i] - 'a');
            int product = ind * (i + 1);
            deg += product;
        }

        return deg;
    }
};