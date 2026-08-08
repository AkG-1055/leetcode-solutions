class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        set<int> used;
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        sort(freq.begin(), freq.end());

        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0 && used.count(freq[i])) {
                freq[i] -= 1;
                count++;
            }
            used.insert(freq[i]);
        }
        
        return count;
    }
};