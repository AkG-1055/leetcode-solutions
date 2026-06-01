class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int max = 1e7;

        for (int i = 0; i < arr.size() - 1; i++){
                int diff = abs(arr[i + 1] - arr[i]);
                if (diff < max){
                    max = diff;
                    ans.clear();
                    ans.push_back({arr[i], arr[i + 1]});
                }
                else if (diff == max){
                    ans.push_back({arr[i], arr[i + 1]});
                }
        }
        return ans;
    }
};