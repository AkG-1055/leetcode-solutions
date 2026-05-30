class Solution {
public:
    void findCombinations(int index, string digits, vector<string>& res, string ds){
        unordered_map <char,string> key = {
            {'2', "abc"} , {'3', "def"} ,
            {'4', "ghi"} , {'5', "jkl"} , {'6', "mno"} ,
            {'7', "pqrs"} , {'8', "tuv"} , {'9', "wxyz"}
        };
        
        if (index == digits.length()){
            res.push_back(ds);
            return;
        }

        string letters = key[digits[index]];

        if (index < digits.length()){
            for (int i = 0; i < letters.length(); i++){
                ds += letters[i];
                findCombinations (index + 1, digits, res, ds);
                ds.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        string ds;
        findCombinations (0, digits, res, ds);
        return res;
    }
};