class Solution {
public:

    int helper(const vector<int>& num, int i, int prev, vector<vector<int>>& dp){
        if(i >= num.size()){
            return 0;
        }

        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }

        int take = 0;
        if(prev == -1 || num[prev] < num[i]){
            take = 1 + helper(num, i+1, i, dp);
        }

        int not_take = helper(num, i+1, prev, dp);

        return dp[i][prev + 1] = max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return helper(nums, 0, -1, dp);
    }
};


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> dp(nums.size(), 1);

//         for(int i=0;i<nums.size();i++){
//             for(int j=0;j<i;j++){
//                 if(nums[j] < nums[i]){
//                     dp[i] = max(dp[j]+1, dp[i]);
//                 }
//             }
//         }
        
//         int maxi = 0;
//         for(int i=0;i<dp.size();i++){
//             maxi = max(maxi, dp[i]);
//         }

//         return maxi;
//     }
// };