class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            need[s1[i] - 'a']++;
        }

        int left = 0;
        
        for (int right = 0; right < s2.length(); right++) {
            window[s2[right] - 'a']++;

            if (right - left + 1 > s1.length()){
                window[s2[left] - 'a']--;
                left++;
            }

            if (window == need) {
                return true;
            }
        }

        return false;
    }
};