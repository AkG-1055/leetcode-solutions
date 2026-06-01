class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        vector<int> dis;

        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (colors[i] != colors[j]){
                    dis.push_back(abs(i - j));
                }
            }
        }
        int max = *max_element(dis.begin(), dis.end());

        return max;
    }
};