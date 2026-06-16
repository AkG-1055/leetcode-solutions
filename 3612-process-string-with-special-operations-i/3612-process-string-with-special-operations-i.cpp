class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string res = "";

        for (int i = 0; i < n; i++){
            if (s[i] >= 'a' && s[i] <= 'z'){
                res = res + s[i];
            }
            else if (s[i] == '*'){
                if (res.length() >= 1){
                    res.erase(res.end() - 1);
                }
            }
            else if (s[i] == '#'){
                string duplicate = res;
                res = res + duplicate;
            }
            else{
                reverse(res.begin(), res.end());
            }
        }
        return res;
    }
};