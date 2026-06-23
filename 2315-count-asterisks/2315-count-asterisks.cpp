class Solution {
public:
    int countAsterisks(string s) {
        vector<int> ind;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '|'){
                ind.push_back(i);
            }
        }

        int n = ind.size();
        int i = n - 2;

        while (i >= 0){
            s.erase(s.begin() + ind[i], s.begin() + (ind[i + 1] + 1));
            i = i - 2;
        }

        int count = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '*'){
                count++;
            }
        }

        return count;
    }
};