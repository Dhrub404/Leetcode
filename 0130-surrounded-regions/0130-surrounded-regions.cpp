//BFS SOLUTION
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         int n = board.size();
//         int m = board[0].size();

//         vector<vector<int>> vis(n, vector<int> (m, 0));
        
//         queue<pair<int,int>> q;
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if((i == 0 || i == n-1 || j == 0 || j == m-1) && vis[i][j] == 0 && board[i][j] == 'O'){
//                     q.push({i,j});
//                     vis[i][j] = 1;
//                 }
//             }
//         }

//         while(!q.empty()){
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();

//             int dirRow[] = {1,-1,0,0};
//             int dirCol[] = {0,0,-1,1};

//             for(int i=0;i<4;i++){
//                 int nr = row + dirRow[i];
//                 int nc = col + dirCol[i];

//                 if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && board[nr][nc] == 'O'){
//                     vis[nr][nc] = 1;
//                     q.push({nr,nc});
//                 }
//             }
//         }

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(vis[i][j] == 0 && board[i][j] == 'O'){
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };


//DFS SOLUTION
class Solution {
public:

    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int row, int col){
        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;

        int dirRow[] = {1, -1, 0, 0};
        int dirCol[] = {0, 0, -1, 1};

        for(int i=0;i<4;i++){
            int nr = row + dirRow[i];
            int nc = col + dirCol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && board[nr][nc] == 'O'){
                dfs(board, vis, nr, nc);
            }
        }
    }

    void solve(vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Start DFS from boundary O's
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && board[i][j] == 'O' && vis[i][j] == 0){
                    dfs(board, vis, i, j);
                }
            }
        }

        // Convert remaining O's to X
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};