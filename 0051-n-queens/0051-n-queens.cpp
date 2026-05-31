class Solution {
public:
    void validPositions(int n, int row, vector<vector<string>>& res,
        vector<string>& ds, unordered_set<int>& c, unordered_set<int>& md, unordered_set<int>& ad) {
        if (ds.size() == n) {
            res.push_back(ds);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!c.count(col) && !md.count(row - col) && !ad.count(row + col)) {
                c.insert(col);
                md.insert(row - col);
                ad.insert(row + col);

                string s;
                for (int i = 0; i < n; i++) {
                    if (i == col) {
                        s.push_back('Q');
                    } else {
                        s.push_back('.');
                    }
                }
                ds.push_back(s);

                validPositions(n, row + 1, res, ds, c, md, ad);
                
                ds.pop_back();
                c.erase(col);
                md.erase(row - col);
                ad.erase(row + col);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> ds;
        unordered_set<int> c, md, ad;
        validPositions(n, 0, res, ds, c, md, ad);
        return res;
    }
};