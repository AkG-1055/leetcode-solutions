class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        string s = "";
        int turn = 0;
        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            if (turn == 0) {
                s.push_back(word1[i]);
                i++;
                turn = 1;
            }
            else{
                s.push_back(word2[j]);
                j++;
                turn = 0;
            }
        }

        if (i < m) {
            while (i < m) {
                s.push_back(word1[i]);
                i++;
            }
        }

        if (j < n) {
            while (j < n) {
                s.push_back(word2[j]);
                j++;
            }
        }

        return s;
    }
};