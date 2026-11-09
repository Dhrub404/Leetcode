class Solution {
public:

    int helper(string& s, int i, int j, vector<vector<int>>& dp){
        if(i > j) return 0;

        if(i == j) return 1;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j]){
            return dp[i][j] = 2 + helper(s, i+1, j-1, dp);
        }

        return dp[i][j] = max( helper(s, i+1, j, dp), helper(s, i, j-1, dp));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(s, 0, n-1, dp);
    }
};



// class Solution {
// public:

//     int fact(vector<vector<int>>& dp, const string& s1, const string& s2, int i, int j){
//         if(i >= s1.size() || j >= s2.size()){
//             return  0;
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         if(s1[i] == s2[j]){
//             return dp[i][j] = 1 + fact(dp,s1,s2,i+1,j+1);
//         }

//         return dp[i][j] = max(fact(dp,s1,s2,i+1,j), fact(dp,s1,s2,i,j+1));
//     }

//     int longestPalindromeSubseq(string s) {
//         string s1 = s;
//         string s2 = s;
//         reverse(s2.begin(), s2.end());

//         vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));

//         int i = s.length() - 1;
//         int j = s.length() - 1;

//         return fact(dp, s1, s2, 0, 0);
//     }
// };