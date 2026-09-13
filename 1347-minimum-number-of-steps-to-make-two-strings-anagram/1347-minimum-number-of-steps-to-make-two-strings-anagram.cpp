class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        int sum = 0;
        for (int f : freq) {
            if (f > 0) {
                sum += f;
            }
        }

        return sum;
    }
};