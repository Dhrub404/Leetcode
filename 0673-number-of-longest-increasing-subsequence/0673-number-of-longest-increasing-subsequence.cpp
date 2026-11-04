class Solution {
public:

    pair<int,int> helper(const vector<int>& num, int i, int prev, vector<vector<pair<int,int>>>& dp){
        if(i >= num.size()){
            return {0, 1};
        }

        if(dp[i][prev+1].first != -1){
            return dp[i][prev+1];
        }

        pair<int,int> take = {0, 0};

        if(prev == -1 || num[prev] < num[i]){
            auto temp = helper(num, i+1, i, dp);
            take = {1 + temp.first, temp.second};
        }

        pair<int,int> not_take = helper(num, i+1, prev, dp);

        if(take.first > not_take.first){
            return dp[i][prev+1] = take;
        }
        else if(take.first < not_take.first){
            return dp[i][prev+1] = not_take;
        }
        else{
            return dp[i][prev+1] = {take.first, take.second + not_take.second};
        }
    }

    int findNumberOfLIS(vector<int>& nums){
        int n = nums.size();

        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n+1, {-1, -1}));

        return helper(nums, 0, -1, dp).second;
    }
};