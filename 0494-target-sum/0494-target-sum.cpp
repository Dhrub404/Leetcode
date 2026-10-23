class Solution {
public:

    int helper(vector<int>& nums, vector<vector<int>> &dp, int i, int sum, int target, int offset){
        if(i == nums.size()){
            if(sum == target)   return 1;
            return 0;
        }

        if(dp[i][sum+offset] != INT_MAX){
            return dp[i][sum+offset];
        }

        int add =  helper(nums, dp, i+1, sum + nums[i], target, offset);
        int sub =  helper(nums, dp, i+1, sum - nums[i], target, offset);

        return dp[i][sum+offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;

        for(int i=0;i<n;i++){
            total += nums[i];
        }

        if(abs(target) > total) return 0;

        vector<vector<int>>dp (n+1, vector<int> (2*total+1, INT_MAX));

        return helper(nums, dp, 0, 0, target, total);
    }
};