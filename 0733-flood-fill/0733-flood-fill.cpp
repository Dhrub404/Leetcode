class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int val, int row, int col, int color){
        vis[row][col] = 1;
        grid[row][col] = color;

        int n = grid.size();
        int m = grid[0].size();

        // Up
        if(row-1 >= 0 && grid[row-1][col] == val && vis[row-1][col] == 0){

            dfs(grid, vis, val, row - 1, col, color);
        }

        // Down
        if(row+1 < n && grid[row+1][col] == val && vis[row+1][col] == 0){
            dfs(grid, vis, val, row + 1, col, color);
        }

        // Left
        if(col-1 >= 0 && grid[row][col-1] == val && vis[row][col-1] == 0){
            dfs(grid, vis, val, row, col-1, color);
        }

        // Right
        if(col+1 < m && grid[row][col+1] == val && vis[row][col+1] == 0){
            dfs(grid, vis, val, row, col+1, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int val = image[sr][sc];

        dfs(image, vis, val, sr, sc, color);

        return image;
    }
};