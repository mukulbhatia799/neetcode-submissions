class Solution {
public:
    int findAns(int currRow, int currCol, int destRow, int destCol, vector<vector<int>>& dp) {
        if(currRow == destRow-1 && currCol == destCol-1) {
            return 1;
        }

        if(dp[currRow][currCol] != -1) return dp[currRow][currCol];

        int ways = 0;
        if(currRow+1 < destRow) {   // bottom
            ways = findAns(currRow+1, currCol, destRow, destCol, dp);
        }
        if(currCol+1 < destCol) {   // right
            ways += findAns(currRow, currCol+1, destRow, destCol, dp);
        }
        return dp[currRow][currCol] = ways;
    }
    int uniquePaths(int m, int n) {
        // brute force approach - O(2^n)
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return findAns(0, 0, m, n, dp);
    }
};