
class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int i, int len, int first, int second, string& s, vector<vector<vector<vector<int>>>>& dp){
        if(len == 5) return 1;

        if(i == s.size()) return 0;

        if(dp[i][len][first][second] != -1){
            return dp[i][len][first][second];
        }

        // Not take
        long long skip = solve(i+1, len, first, second, s, dp);

        // Take
        long long take = 0;
        int digit = s[i] - '0';

        if(len == 0){
            take = solve(i+1, len+1, digit, second, s, dp);
        }
        else if(len == 1){
            take = solve(i+1, len+1, first, digit, s, dp);
        }
        else if(len == 2){
            take = solve(i+1, len+1, first, second, s, dp);
        }
        else if(len == 3 && digit == second){
            take = solve(i+1, len+1, first, second, s, dp);
        }
        else if(len == 4 && digit == first){
            take = solve(i+1, len+1, first, second, s, dp);
        }

        return dp[i][len][first][second] = (take + skip) % mod;
    }

    int countPalindromes(string s) {
        int n = s.size();

        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(
                5, vector<vector<int>>(
                    10, vector<int>(10, -1)
                )
            )
        );

        return solve(0, 0, 0, 0, s, dp);
    }
};
