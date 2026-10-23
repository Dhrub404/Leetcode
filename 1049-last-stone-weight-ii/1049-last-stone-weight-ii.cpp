
class Solution {
public:

    int helper(vector<int>& stones, vector<vector<int>>& dp, int i, int sum1, int sum2, int target) {
        if(i == stones.size()){
            return abs(sum1 - sum2);
        }

        if(dp[i][sum1] != -1){
            return dp[i][sum1];
        }

        int take = helper(stones, dp, i+1, sum1+stones[i], sum2, target);

        int notTake = helper(stones, dp, i+1, sum1, sum2+stones[i], target);

        return dp[i][sum1] = min(take, notTake);
    }

    int lastStoneWeightII(vector<int>& stones){
        int n = stones.size();
        int sum = 0;

        for(int i=0;i<n;i++){
            sum += stones[i];
        }

        int target = sum;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return helper(stones, dp, 0, 0, 0, target);
    }
};
