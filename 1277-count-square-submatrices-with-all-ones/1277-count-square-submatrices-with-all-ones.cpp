class Solution {
public:

    int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i , int j){
        int n = matrix.size();
        int m = matrix[0].size();

        if(i >= n || j >= m){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(matrix[i][j] == 0){
            return dp[i][j] = 0;
        }

        int right = helper(matrix, dp, i, j+1);
        int bottom = helper(matrix, dp, i+1, j);
        int bottom_right = helper(matrix, dp, i+1, j+1);

        return dp[i][j] = 1 + min(right, min(bottom, bottom_right));
    }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n , vector<int> (m, -1));
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1){
                    ans += helper(matrix, dp, i, j);
                }
            }
        }


        return ans;
    }
};