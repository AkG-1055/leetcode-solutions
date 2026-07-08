class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;

        for (char c : to_string(n)) {
            if (c == '0') continue;

            int d = c - '0';
            x = x * 10 + d;
            sum += d;
        }

        return x * sum;
    }
};