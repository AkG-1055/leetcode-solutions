class Solution {
public:
    int findSum(int& curr) {
        int sum = 0;
        while (curr >= 1) {
            int digit = curr %  10;
            sum += digit;
            curr = curr / 10;
        }
        return sum;
    }

    int addDigits(int num) {
        int curr = num;

        while (curr >= 10) {
            curr = findSum(curr);
        }
        
        return curr;
    }
};