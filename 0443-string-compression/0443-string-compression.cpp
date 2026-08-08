class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0;
        int write = 0;

        for (int right = 0; right < chars.size(); right++) {
            if (chars[right] == chars[left]) {
                continue;
            }
            else{
                int length = right - left;
                chars[write] = chars[left];
                write++;
                if (length > 1) {
                    string count = to_string(length);
                    for (char c : count) {
                        chars[write] = c;
                        write++;
                    }
                }
                left = right;
            }
        }

        chars[write] = chars[left];
        write++;
        if (chars.size() - left > 1) {
            string count = to_string(chars.size() - left);
            for (char c : count) {
                chars[write] = c;
                write++;
            }
        }
        return write;
    }
};