class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int> curr_row;
        curr_row.push_back(ans);

        for (int c = 1; c <= rowIndex; c++){
            ans = ans * ((rowIndex + 1) - c);
            ans = ans / c;
            curr_row.push_back(ans);
        }
        return curr_row;
    }
};