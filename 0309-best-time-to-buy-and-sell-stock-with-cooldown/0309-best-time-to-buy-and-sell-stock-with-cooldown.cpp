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
            int sell = prices[i] + helper(prices, dp, i+2, 1);
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






// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//       int n=prices.size();
//         if(prices.size()==1){
//             return 0;
//         }
        
//       //initialise two vector for storing the value after buying and selling stock...
//       vector<int>buy(n,0);
//       vector<int>sell(n,0);

//       //we bought first stock 0n very first day
//       buy[0]=-prices[0];
//       //no profit on first day
//       sell[0]=0;

//       //on second day check which day will give us more profit on buying stock 1st day/2nd day
//       buy[1]=max(-prices[0],-prices[1]);
//       //check if we can sell our stock on 2nd day or not with some profit
//       sell[1]=max(0,-prices[0]+prices[1]);

//       for(int i=2;i<n;i++){
//         //we have to make desicion either we can buy stock or not i.e we have to sell i-2th item to buy ith item . so we need to choose wisely that if we can make more profit on buying ith stock or not.
//         buy[i]=max(buy[i-1],sell[i-2]-prices[i]);

//         //simillarly we need to check on which day to sell the stock to make more profit
//         sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
//       }
      
//       //return profit after selling nth item.
//         return sell[n-1];
//     }
// };