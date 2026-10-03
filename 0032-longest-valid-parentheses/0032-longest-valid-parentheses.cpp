class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int max_count = 0;
        int last = -1;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                st.push(i);
            }
            else {
                if (!st.empty()) {
                    st.pop();

                    if (!st.empty()) {
                        max_count = max(max_count, i - st.top());
                    }
                    else {
                        max_count = max(max_count, i - last);
                    }
                }
                else {
                    last = i;
                }
            }
        }

        return max_count;
    }
};