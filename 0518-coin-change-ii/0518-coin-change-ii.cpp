class Solution {
public:

    int helper(vector<int>& coins, vector<vector<int>>& dp, int i, int amount) {
        if(amount == 0) return 1;

        if(i >= coins.size()) return 0;

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int inc = 0;
        if(coins[i] <= amount){
            inc = helper(coins, dp, i, amount-coins[i]);
        }

        int exc = helper(coins, dp, i+1, amount);

        return dp[i][amount] = inc + exc;
    }

    int change(int amount, vector<int>& coins){
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return helper(coins, dp, 0, amount);
    }
};