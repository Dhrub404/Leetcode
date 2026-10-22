class Solution {
public:

    int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j){
        int n = triangle.size();
        int m = triangle[0].size();

        if(i == n-1) return triangle[i][j];

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int down = helper(triangle, dp, i+1, j);

        int rightDiagonal = helper(triangle, dp, i+1, j+1);

        return dp[i][j] = triangle[i][j] +  min(down, rightDiagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        if(n == 1)  return triangle[0][0];

        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));


        return helper(triangle, dp, 0, 0);
    }
};