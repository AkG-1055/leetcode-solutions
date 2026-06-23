class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> seen;

        for (char ch : password){
            if (seen.count(ch)) continue;

            seen.insert(ch);
        }

        int count = 0;
        for (char ch : seen){
            if (ch >= 'a' && ch <= 'z'){
                count += 1;
            }
            else if (ch >= 'A' && ch <= 'Z'){
                count += 2;
            }
            else if (ch >= '0' && ch <= '9'){
                count += 3;
            }
            else{
                count += 5;
            }
        }

        return count;
    }
};