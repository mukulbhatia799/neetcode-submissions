class Solution {
public:
    int func(int n, vector<int> &dp) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = func(n-1, dp) + func(n-2, dp);
    }
    int climbStairs(int n) {
        // Memoization approach - t.c -> O(n), s.c -> O(n) + O(n) {dp array + recursive stack space}
        vector<int> dp(n+1, -1);
        return func(n, dp);
    }
};