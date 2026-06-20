class Solution {
public:
    string reverseWords(string s) {
        int sp_index = 0;
        
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ' '){
                reverse(s.begin() + sp_index, s.begin() + i);
                sp_index = i + 1;
            }
        }
        reverse(s.begin() + sp_index, s.end());
        return s;
    }
};