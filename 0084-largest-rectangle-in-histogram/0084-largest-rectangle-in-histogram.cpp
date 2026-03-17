class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();
        int pse, nse, element;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                element = st.top();
                st.pop();

                nse = i;
                if (st.empty()) {
                    pse = -1;
                } 
                else {
                    pse = st.top();
                }

                maxA = max(maxA, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            nse = n;
            element = st.top();
            st.pop();
            if (st.empty()) {
                pse = -1;
            } else {
                pse = st.top();
            }
            maxA = max(maxA, heights[element] * (nse - pse - 1));
        }
        return maxA;
    }
};