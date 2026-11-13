
class Solution {
public:
    bool solve(int i, int start, string& s, unordered_set<string>& dictionary, vector<vector<int>>& dp){
        if(i == s.size()){
            string curr = s.substr(start, i - start);
            return dictionary.find(curr) != dictionary.end();
        }

        if(dp[i][start] != -1){
            return dp[i][start];
        }

        // take current character
        bool take = solve(i+1, start, s, dictionary, dp);

        // Skip :: finish current word if it exists
        bool skip = false;

        string curr = s.substr(start, i-start+1);

        if(dictionary.find(curr) != dictionary.end()){
            skip = solve(i+1, i+1, s, dictionary, dp);
        }

        return dp[i][start] = (take || skip);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictionary(wordDict.begin(), wordDict.end());
        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(0, 0, s, dictionary, dp);
    }
};
