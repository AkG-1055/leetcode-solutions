class Solution {
public:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> curr_row;
        curr_row.push_back(ans);

        for (int c = 1; c < row; c++){
            ans = ans * (row - c);
            ans = ans / (c);
            curr_row.push_back(ans);
        }
        return curr_row;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i++){
            vector<int> r;
            r = generateRow(i);
            res.push_back(r);
        }
        return res;
    }
};