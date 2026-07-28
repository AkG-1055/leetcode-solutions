class Solution {
    public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string left = "";
        string mid = "";

        for (int i = 0; i < 26; i++) {
            int contri = freq[i] / 2;

            left.append(contri, 'a' + i);

            if (freq[i] % 2 != 0) {
                mid = 'a' + i;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};