class Solution {
public:

    int helper(string &word1, string &word2, vector<vector<int>> &dp, int i, int j){
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
            return dp[i][j] = helper(word1, word2, dp, i+1, j+1);
        }

        return dp[i][j] = 1 + min(helper(word1, word2, dp, i+1, j), helper(word1, word2, dp, i, j+1));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp (n, vector<int>(m, -1));

        return helper(word1, word2, dp, 0, 0);
    }
};