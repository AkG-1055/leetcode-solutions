class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int color, int original) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() ||
            image[i][j] == color) {
            return;
        }
        
        if (image[i][j] == original){
            image[i][j] = color;
        }
        else{
            return;
        }

        dfs(i - 1, j, image, color, original);
        dfs(i + 1, j, image, color, original);
        dfs(i, j - 1, image, color, original);
        dfs(i, j + 1, image, color, original);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if (image[sr][sc] != color) {
            int original = image[sr][sc];
            image[sr][sc] = color;
            dfs(sr - 1, sc, image, color, original);
            dfs(sr + 1, sc, image, color, original);
            dfs(sr, sc - 1, image, color, original);
            dfs(sr, sc + 1, image, color, original);
        }
        return image;
    }
};