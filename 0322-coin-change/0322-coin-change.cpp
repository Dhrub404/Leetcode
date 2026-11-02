class Solution {
public:

    int helper(vector<int>& coins, vector<vector<int>> &dp, int amount, int i){
        if(i >= coins.size()){
            return INT_MAX;
        }
        if(amount == 0) return 0;

        if(dp[i][amount] != -1){
            return dp[i][amount];
        } 

        int inc = INT_MAX;
        if(coins[i] <= amount){
            int temp = helper(coins, dp, amount - coins[i], i);

            if(temp != INT_MAX){
                inc = 1 + temp;
            }
        }
        int exc = helper(coins, dp, amount, i+1);

        return dp[i][amount] = min(inc, exc);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

        int ans = helper(coins, dp, amount, 0);

        return ans == INT_MAX ? -1 : ans;
    }
};