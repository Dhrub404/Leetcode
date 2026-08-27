class Solution {
public:

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;   //((row, col), distance)

        q.push({{0, 0}, 1});
        vis[0][0] = 1;

        int dr[] = {-1,1,0,0,-1,-1,1,1};
        int dc[] = {0,0,-1,1,-1,1,-1,1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            if(row == n-1 && col == m-1)
                return dist;

            for(int i=0;i<8;i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, dist+1});
                }
            }
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)  return -1;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        return bfs(grid, vis);
    }
};