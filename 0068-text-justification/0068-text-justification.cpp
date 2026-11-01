class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0;
        int j = 0;
        int lineLength = 0;

        while (i < words.size()) {
            string curr = "";
            while (j < words.size() &&
                   lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }

            int totalSpaces = maxWidth - lineLength;
            int gaps = j - i - 1;

            string line = "";

            if (j == words.size() || gaps == 0) {

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += " ";
                    }
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                int spacesPerGap = 1;
                int extraSpaces = 0;

                if (gaps != 0) {
                    spacesPerGap = totalSpaces / gaps;
                    extraSpaces = totalSpaces % gaps;
                }

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += string(spacesPerGap, ' ');

                        if (extraSpaces > 0) {
                            line += " ";
                            extraSpaces--;
                        }
                    }
                }
            }

            res.push_back(line);
            i = j;
            lineLength = 0;
        }

        return res;
    }
};