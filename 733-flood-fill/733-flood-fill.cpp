class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        dfs(sr, sc, image[sr][sc], newColor, image, vis);
        return image;
    }
    
private:
    void dfs(int r, int c, int startColor, int newColor, vector<vector<int>> &img, vector<vector<int>> &vis) {
        if (!valid(r, c, img) || vis[r][c] || img[r][c] != startColor)
            return;
        
        vis[r][c] = 1;
        img[r][c] = newColor;
        
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};
        
        for (int i = 0 ; i < 4 ; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            dfs(new_r, new_c, startColor, newColor, img, vis);
        }
    }
    
    bool valid(int r, int c, vector<vector<int>> &img) {
        int m = img.size(), n = img[0].size();
        return (r >= 0 && r < m && c >= 0 && c < n);
    }
};