class Solution {
public:

    bool helper(vector<int>& nums,vector<vector<int>>&dp, int i, int target){
        //base cases
        if(target == 0)  return true;
        if(i == nums.size())     return false;

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        bool nottake = helper(nums, dp, i+1, target);
        bool take = false;

        if(target >= nums[i]){
            take = helper(nums, dp, i+1, target-nums[i]);
        }

        return dp[i][target] = (take || nottake);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }

        //if sum is odd then its not possible to get 2 equal halves
        if(sum%2 != 0){
            return false;
        }

        int target = sum/2;
        vector<vector<int>>dp(nums.size(), vector<int>(target+1, -1));  

        return helper(nums,dp,0,target);
    }
};