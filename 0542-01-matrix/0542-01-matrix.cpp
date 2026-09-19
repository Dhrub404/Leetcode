class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, -1));
        vector<vector<int>> ans(n, vector<int> (m, 0));
        
        queue<pair<pair<int,int>, int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == -1 && grid[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            ans[row][col] = steps;
            
            int dirRow[] = {0,0,1,-1};
            int dirCol[] = {1,-1,0,0};
            
            for(int i=0;i<4;i++){
                int nr = row + dirRow[i];
                int nc = col + dirCol[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == -1){
                    vis[nr][nc] = 1;
                    q.push({{nr,nc}, steps+1});
                }
            }
        }
        
        return ans;
    }
};