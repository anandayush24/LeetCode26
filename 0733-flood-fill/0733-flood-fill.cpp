class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int target, int color) {
        if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size() 
            || image[r][c] != target) return;

        image[r][c] = color;

        dfs(image, r - 1, c, target, color);
        dfs(image, r + 1, c, target, color);
        dfs(image, r, c - 1, target, color);
        dfs(image, r, c + 1, target, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target = image[sr][sc];
        if (target != color)
            dfs(image, sr, sc, target, color);
        return image;
    }
};