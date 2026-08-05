class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                char low = static_cast<char>(tolower(s[i]));
                s[i] = low;
            }
        }
        return s;
    }
};