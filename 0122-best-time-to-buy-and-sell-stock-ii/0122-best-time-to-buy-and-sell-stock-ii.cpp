class Solution {
public:

    int helper(vector<int>& prices, vector<vector<int>> &dp, int i, int buy){
        if(i >= prices.size())  return 0;

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;

        if(buy){
            int take = -prices[i] + helper(prices, dp, i+1, 0);
            int notTake = helper(prices, dp, i+1, 1);

            profit = max(take, notTake);
        }
        else{
            int sell = prices[i] + helper(prices, dp, i+1, 1);
            int notSell = helper(prices, dp, i+1, 0);

            profit = max(sell, notSell);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));

        return helper(prices, dp, 0, 1);
    }
};