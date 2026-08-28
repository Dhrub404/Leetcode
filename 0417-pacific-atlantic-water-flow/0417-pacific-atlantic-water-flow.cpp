class Solution {
public:

    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &vis, int row, int col){
        vis[row][col] = true;
        int n = heights.size();
        int m = heights[0].size();

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            
            if(vis[nr][nc]) continue;

            if(heights[nr][nc] < heights[row][col]) continue;

            dfs(heights, vis, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        vector<vector<int>> ans;

        //pacific
        for(int i=0;i<m;i++){
            dfs(heights, pacific, 0, i);
        }
        for(int i=0;i<n;i++){
            dfs(heights, pacific, i, 0);
        }

        //atlantic
        for(int i=0;i<n;i++){
            dfs(heights, atlantic, i, m-1);
        }
        for(int i=0;i<m;i++){
            dfs(heights, atlantic, n-1, i);
        }

        //checking for common heights
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};