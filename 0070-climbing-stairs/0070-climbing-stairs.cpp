class Solution {
public:

    int helper(vector<int> &dp, int n){
        if(n == 0 || n == 1)  return 1;

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = helper(dp, n-1) + helper(dp, n-2);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        return helper(dp, n);
    }
};



// class Solution {
// public:

//     // //Approach 2: Memoization
//     // int helper(int n, unordered_map<int, int>& memo){
//     //     if(n == 0 || n == 1){
//     //         return 1;
//     //     }
//     //     if(memo.find(n) == memo.end()){
//     //         memo[n] = helper(n-1, memo) + helper(n-2, memo);
//     //     }
//     //     return memo[n];
//     // }

//     // int climbStairs(int n) {
//     //     unordered_map<int, int> memo;
//     //     return helper(n, memo);
//     // }
// };

// //approach 2 memoization without unordered map
// class Solution {
// public:

//     int helper(int n, vector<int>& memo){
//         if(n == 0 || n == 1){
//             return 1;
//         }

//         // If already calculated, return it
//         if(memo[n] != -1){
//             return memo[n];
//         }

//         // Otherwise calculate and store
//         memo[n] = helper(n-1, memo) + helper(n-2, memo);

//         return memo[n];
//     }

//     int climbStairs(int n){
//         vector<int> memo(n+1, -1);

//         return helper(n, memo);
//     }
// };

// aproach 1 space optimized
// class Solution {
// public:
//     int climbStairs(int n){
//         if(n == 0 || n == 1){
//             return 1;
//         }
//         int prev = 1; 
//         int curr = 1;

//         for(int i=2;i<=n;i++){
//             int temp = curr;
//             curr = prev + curr;
//             prev = temp;
//         }

//         return curr;
//     }
// };

// //tabulation
// class Solution {
// public:
//     int climbStairs(int n){
//         if(n == 0 || n == 1){
//             return 1;
//         }
//         vector<int> dp(n+1, -1);
//         dp[0] = 0;
//         dp[1] = 1;
//         dp[2] = 2;

//         for(int i=3;i<=n;i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         }

//         return dp[n];
//     }
// };

