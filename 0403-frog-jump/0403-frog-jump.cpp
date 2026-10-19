class Solution {
public:
    unordered_map<int, int> pos;

    bool helper(vector<int>& stones, vector<vector<int>>& dp,int i, int jump, int n){
        if (i == n-1) return true;

        if(dp[i][jump] != -1){
            return dp[i][jump];
        }

        for(int next=jump-1;next<=jump+1;next++){
            if (next <= 0) continue;

            int nextPosition = stones[i] + next;

            if(pos.count(nextPosition)){
                int nextIndex = pos[nextPosition];

                if(helper(stones, dp, nextIndex, next, n) == true){
                    return dp[i][jump] = true;
                }
            }
        }

        return dp[i][jump] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n == 1) return true;
        if(stones[1] != 1) return false;

        for(int i=0;i<n;i++){
            pos[stones[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(stones, dp, 1, 1, n);
    }
};