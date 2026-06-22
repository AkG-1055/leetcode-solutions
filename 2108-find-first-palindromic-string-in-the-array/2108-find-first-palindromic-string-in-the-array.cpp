class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++){
            int n = words[i].length();
            int left = 0;
            int right = n - 1;
            bool isPal = true;

            while (left <= right){
                if (words[i][left] != words[i][right]){
                    isPal = false;
                    break;
                }
                left++;
                right--;
            }
            if (isPal){
                return words[i];
            }
        }
        return "";
    }
};