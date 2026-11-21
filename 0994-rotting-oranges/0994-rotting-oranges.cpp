class Solution {
public:

    int bfs(vector<vector<int>> &grid, vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        
        //all rotten oranges push to queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int count = 0;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){
            int size = q.size();
            bool check = false;

            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if((nr >= 0 && nr < n) && (nc >= 0 && nc < m) && grid[nr][nc] == 1 && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        check = true;
                    }
                }
            }

            if(check)   count++;
        }

        return count;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));

        int count = bfs(grid, vis);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return count;
    }
};