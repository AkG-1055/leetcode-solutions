class Solution {
public:
    int maxVowels(string s, int k) {
        int max_count = 0;
        int count = 0;
        unordered_set<char> seen = {'a', 'e', 'i', 'o', 'u'};
        int right = k;

        for (int left = right - k; left < right; left++) {
            if (seen.count(s[left]) != 0) {
                count++;
            }
        }
        max_count = max(max_count, count);
        right++;

        while (right <= s.length()) {
            int left = right - k - 1;
            if (seen.count(s[left]) != 0 && seen.count(s[right - 1]) != 0 || seen.count(s[left]) == 0 && seen.count(s[right - 1]) == 0) {
                max_count = max(max_count, count);
                right++;
                continue;
            }
            else if (seen.count(s[left]) != 0 && seen.count(s[right - 1]) == 0) {
                count--;
            }
            else {
                count++;
            }
            max_count = max(max_count, count);
            right++;
        }

        return max_count;
    }
};