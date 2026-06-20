class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        int i = 0;

        while (i < n){
            int size = n - i; 
            if (size >= 2*k){
                reverse(s.begin() + i, s.begin() + (i + k));
                i = i + 2*k;
            }
            else if (k <= size && size < (2*k)){
                reverse(s.begin() + i, s.begin() + (i + k));
                i = i + 2*k;
            }
            else{
                reverse(s.begin() + i, s.end());
                i = i + 2*k;
            }
        }

        return s;
    }
};