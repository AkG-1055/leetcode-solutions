class Solution {
public:
    string interpret(string command) {
        string s = "";
        for (int i = 0; i < command.length(); i++) {
            if (command[i] == 'G') {
                s.push_back('G');
            }
            else if (command[i] == '(' && command[i + 1] == 'a') {
                s.push_back('a');
                s.push_back('l');
            }
            else if (command[i] == '(' && command[i + 1] == ')'){
                s.push_back('o');
            }
        }
        return s;
    }
};