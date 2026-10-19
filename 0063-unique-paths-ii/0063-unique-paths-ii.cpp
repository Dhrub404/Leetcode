//memoization
class Solution {
public:

    int helper(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(i >= m || j >= n)    return 0;

        if(obstacleGrid[i][j] == 1){
            return 0;
        }

        if(i == m-1 && j == n-1){
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = helper(obstacleGrid, dp, i + 1, j);
        int right = helper(obstacleGrid, dp, i, j + 1);

        dp[i][j] = down + right;

        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(obstacleGrid, dp, 0, 0);
    }
};






// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();       
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         // If starting cell itself has an obstacle
//         if (obstacleGrid[0][0] == 1)
//             return 0;

//         // Starting point
//         dp[0][0] = 1;

//         // Fill the first column
//         for (int i = 1; i < m; i++) {
//             if (obstacleGrid[i][0] == 0){
//                 dp[i][0] = dp[i-1][0];
//             }
//         }

//         // Fill the first row
//         for (int j = 1; j < n; j++) {
//             if (obstacleGrid[0][j] == 0){
//                 dp[0][j] = dp[0][j-1];
//             }
//         }

//         // Fill remaining cells
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {

//                 // Obstacle => no path
//                 if (obstacleGrid[i][j] == 1) {
//                     dp[i][j] = 0;
//                 }
//                 else {
//                     dp[i][j] = dp[i-1][j] + dp[i][j-1];
//                 }
//             }
//         }

//         return dp[m-1][n-1];
//     }
// };