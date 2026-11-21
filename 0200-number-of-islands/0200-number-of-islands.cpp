// class Solution {
// public:

    


//     //using dfs
//     void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis,int row, int col){
//         vis[row][col] = 1;

//         int n = grid.size();
//         int m = grid[0].size();

//         // Up
//         if(row-1 >= 0 && grid[row-1][col] == '1' && vis[row-1][col] == 0){
//             dfs(grid, vis, row - 1, col);
//         }

//         // Down
//         if(row+1 < n && grid[row+1][col] == '1' &&vis[row+1][col] == 0){
//             dfs(grid, vis, row + 1, col);
//         }

//         // Left
//         if(col-1 >= 0 && grid[row][col-1] == '1' && vis[row][col-1] == 0){
//             dfs(grid, vis, row, col-1);
//         }

//         // Right
//         if(col+1 < m && grid[row][col+1] == '1' && vis[row][col+1] == 0){
//             dfs(grid, vis, row, col+1);
//         }
//     }
    
//     int numIslands(vector<vector<char>>& grid) {
//         int count = 0;
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n, vector<int>(m, 0));

//         for(int row=0;row<n;row++){
//             for(int col=0;col<m;col++){
//                 if(grid[row][col] == '1' && !vis[row][col]){
//                     count++;
//                     dfs(grid, vis, row, col);
//                 }
//             }
//         }

//         return count;
//     }
// };



class Solution {
public:

    void bfs_helper(vector<vector<char>>& grid, vector<vector<int>>& visited, int row, int col){
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row, col});
        

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse all neighbours and mark them if its a land

            //using 4 direction matrix 
            // 4 directions up down left  right
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for(int i=0;i<4;i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                // Check boundaries and whether it is land
                if((nr >= 0 && nr < n) && (nc >= 0 && nc < m) && grid[nr][nc] == '1' && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col] == '1' && !vis[row][col]){
                    count++;
                    bfs_helper(grid, vis, row, col);
                }
            }
        }

        return count;
    }
};