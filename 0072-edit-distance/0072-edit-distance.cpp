
class Solution {
public:

    int helper(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
        if(i == word1.size()){
            return word2.size() - j;
        }

        if(j == word2.size()){
            return word1.size() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(word1[i] == word2[j]){
            return dp[i][j] = helper(i+1, j+1, word1, word2, dp);
        }

        // insertion call
        int insert = 1 + helper(i, j+1, word1, word2, dp);

        // deletion call
        int del = 1 + helper(i+1, j, word1, word2, dp);

        // Replace call
        int replace = 1 + helper(i+1, j+1, word1, word2, dp);

        return dp[i][j] = min({insert, del, replace});
    }

    int minDistance(string word1, string word2){
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(0, 0, word1, word2, dp);
    }
};
