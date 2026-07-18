class Solution {
public:
    int findAns(vector<vector<int>>& dp, int m, int n, int row, int col) {
        if(row == m-1 && col == n-1) {
            return 1;
        }
        if(dp[row][col] != -1) return dp[row][col];
        int count = 0;
        if(row+1 < m) {
            // bottom
            count = findAns(dp, m, n, row+1, col);
        }
        if(col+1 < n) {
            // right
            count += findAns(dp, m, n, row, col+1);
        }

        return dp[row][col] = count;
    }
    int uniquePaths(int m, int n) {
        // using memoization
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findAns(dp, m, n, 0, 0);
    }
};