class Solution {
public:
    int findAns(int n, int ind, vector<int>& dp) {
        if(ind == n) return 1;
        if(ind > n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int ans = findAns(n, ind+1, dp);
        ans += findAns(n, ind+2, dp);
        return dp[ind] = ans;
    }
    int climbStairs(int n) {
        // memoization
        vector<int> dp(n+1, -1);
        return findAns(n, 0, dp);
    }
};