class Solution {
public:
    vector<int> findNSE(vector<int> & arr) {
            int n = arr.size();
            vector<int> nse(n);
            stack<int> st;

            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
                    if (st.empty()) {
                        nse[i] = n;
                    } 
                    else {
                        nse[i] = st.top();
                    }
                st.push(i);
            }
            return nse;
        }
    
    vector<int> findPSEE(vector<int> & arr) {
            int n = arr.size();
            vector<int> pse(n);
            stack<int> st;

            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] > arr[i]) st.pop();

                    if (st.empty()) {
                        pse[i] = -1;
                    } 
                    else {
                        pse[i] = st.top();
                    }
                st.push(i);
            }
            return pse;
        }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;

        int sum = 0;
         
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSEE(arr);

        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            sum = (sum + (1LL * left * right * arr[i]) % mod) % mod;
        }
        return sum;
    }
};