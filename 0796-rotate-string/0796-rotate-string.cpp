class Solution {
public:
    bool rotateString(string s, string goal) {
        for (int i = 1; i <= s.length(); i++) {
            string original = s;
            reverse(s.begin(), s.end());
            reverse(s.begin(), s.begin() + i);
            reverse(s.begin() + i, s.end());

            if (s == goal) {
                return true;
            }
            else{
                s = original;
            }
        }
        return false;
    }
};