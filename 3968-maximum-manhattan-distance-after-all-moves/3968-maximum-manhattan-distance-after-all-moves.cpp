class Solution {
public:
    int maxDistance(string moves) {
        int h = 0;
        int v = 0;
        int count = 0;

        for (int i = 0; i < moves.length(); i++) {
            if (moves[i] == 'L') {
                h--;
            }
            else if (moves[i] == 'R') {
                h++;
            }
            else if (moves[i] == 'U') {
                v++;
            }
            else if (moves[i] == 'D') {
                v--;
            }
            else {
                count++;
            }
        }

        return abs(h - 0) + abs(v - 0) + count;
    }
};