class Solution {
public:
    int findAns(int currRow, int currCol, int destRow, int destCol, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
        if(currRow == destRow-1 && currCol == destCol-1) {
            return 1;
        }

        if(dp[currRow][currCol] != -1) return dp[currRow][currCol];

        int ways = 0;
        if(currRow+1 < destRow && obstacleGrid[currRow+1][currCol] == 0) {   // bottom
            ways = findAns(currRow+1, currCol, destRow, destCol, dp, obstacleGrid);
        }
        if(currCol+1 < destCol && obstacleGrid[currRow][currCol+1] == 0) {   // right
            ways += findAns(currRow, currCol+1, destRow, destCol, dp, obstacleGrid);
        }
        return dp[currRow][currCol] = ways;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // memoization approach - O(2^n)
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findAns(0, 0, m, n, dp, obstacleGrid);
    }
};