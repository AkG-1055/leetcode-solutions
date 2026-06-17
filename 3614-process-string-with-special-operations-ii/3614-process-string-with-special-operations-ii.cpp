class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n);
        
        long long curr = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (curr > 0) curr--;
            } 
            else if (s[i] == '#') {
                curr *= 2;
            } 
            else if (s[i] == '%') {
            } 
            else {
                curr++;
            }
            
            len[i] = curr;
        }
        
        if (n == 0 || k >= len[n - 1]) return '.';
        
        for (int i = n - 1; i >= 0; i--) {
            long long oldLen = (i == 0 ? 0 : len[i - 1]);
            
            if (s[i] == '#') {
                k %= oldLen;
            } 
            else if (s[i] == '%') {
                k = oldLen - 1 - k;
            } 
            else if (s[i] == '*') {
            } 
            else {
                if (k == oldLen) return s[i];
            }
        }
        
        return '.';
    }
};