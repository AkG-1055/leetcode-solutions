class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int diff = 0;

        for (int i = 0; i < s.length(); i++){
            for (int j = 0; j < t.length(); j++){
                if (s[i] == t[j]){
                    diff = diff + abs(i - j);
                    break;
                }
            }
        }
        
        return diff;
    }
};