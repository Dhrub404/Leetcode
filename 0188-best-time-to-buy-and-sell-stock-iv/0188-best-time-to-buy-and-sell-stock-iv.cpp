class Solution {
public:

    int helper(vector<int>& prices, vector<vector<vector<int>>> &dp, int i, int buy, int k){
        if(i >= prices.size())  return 0;

        if(k <= 0)  return 0;

        if(dp[i][buy][k] != -1){
            return dp[i][buy][k];
        }

        int profit = 0;

        if(buy){
            int take = -prices[i] + helper(prices, dp, i+1, 0, k);
            int notTake = helper(prices, dp, i+1, 1, k);

            profit = max(take, notTake);
        }
        else{
            int sell = prices[i] + helper(prices, dp, i+1, 1, k-1);
            int notSell = helper(prices, dp, i+1, 0, k);

            profit = max(sell, notSell);
        }

        return dp[i][buy][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));

        return helper(prices, dp, 0, 1, k);
    }
};