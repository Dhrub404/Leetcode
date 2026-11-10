
class Solution {
public:

    int helper(string& s, int i, int j, vector<vector<int>>& dp) {
        if(i >= j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j]){
            return dp[i][j] = helper(s, i+1, j-1, dp);
        }

        return dp[i][j] = 1 + min(helper(s, i+1, j, dp),helper(s, i, j-1, dp));
    }

    int minInsertions(string s){
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(s, 0, n-1, dp);
    }
};




// class Solution {
// public:
//     //using longest palindromic subsequence
//     int helper(string& s, int i, int j, vector<vector<int>>& dp) {
//         if(i > j){
//             return 0;
//         }

//         if(i == j){
//             return 1;
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
            
//         if(s[i] == s[j]){
//             return dp[i][j] = 2 + helper(s, i+1, j-1, dp);
//         }  
        
//         return dp[i][j] = max(helper(s, i+1, j, dp), helper(s, i, j-1, dp));
//     }
//     int minInsertions(string s) {
//         int n = s.length();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
    
//         return n - helper(s, 0, n-1, dp);
//     }
// };