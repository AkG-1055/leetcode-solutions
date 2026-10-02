class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int left = 0;
        int right = p.length() - 1;
        while (right < s.length()) {
            vector<int> freq(26, 0);

            for (int i = 0; i < p.length(); i++) {
                freq[p[i] - 'a']++;
            }

            for (int i = left; i <= right; i++) {
                freq[s[i] - 'a']--;
            }
            
            bool anagram = true;
            for (int f : freq) {
                if (f != 0) {
                    anagram = false;
                    break;
                }
            }

            if (anagram == true) {
                ans.push_back(left);
            }

            left++;
            right++;
        }

        return ans; 
    }
};