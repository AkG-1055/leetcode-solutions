class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;

        string ans = "";
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int n1 = 0;
            int n2 = 0;
            
            if (i >= 0) {
                n1 = a[i] - '0';
            }

            if (j >= 0) {
                n2 = b[j] - '0';
            }

            int sum = n1 + n2 + carry;

            ans.push_back((sum % 2) + '0');
            carry = sum / 2;

            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};