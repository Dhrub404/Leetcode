
class Solution {
public:

    bool helper(string& s, int si, string& p, int pi, vector<vector<int>>& dp){
        // Base cases
        if(si == s.size() && pi == p.size()){
            return true;
        }

        if(si == s.size() && pi < p.size()){
            while(pi < p.size()){
                if(p[pi] != '*'){
                    return false;
                }
                pi++;
            }
            return true;
        }

        if(pi == p.size()){
            return false;
        }

        if(dp[si][pi] != -1){
            return dp[si][pi];
        }

        // Single character matching
        if(s[si] == p[pi] || p[pi] == '?') {
            return dp[si][pi] = helper(s, si+1, p, pi+1, dp);
        }

        if(p[pi] == '*'){
            // Case A: Treat * as empty
            bool caseA = helper(s, si, p, pi+1, dp);

            // Case B: Let * consume one character
            bool caseB = helper(s, si+1, p, pi, dp);

            return dp[si][pi] = caseA || caseB;
        }

        // Character doesn't match
        return dp[si][pi] = false;
    }

    bool isMatch(string s, string p){
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(s, 0, p, 0, dp);
    }
};
