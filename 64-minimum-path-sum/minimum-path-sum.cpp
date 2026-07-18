class Solution {
public:
    int findAns(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col) {
        if(row == grid.size()-1 && col == grid[0].size()-1) return grid[row][col];
        if(row >= grid.size() || col >= grid[0].size()) return 1e5;

        if(dp[row][col] != -1) return dp[row][col];
        int down = grid[row][col] + findAns(grid, dp, row+1, col);
        int right = grid[row][col] + findAns(grid, dp, row, col+1);

        return dp[row][col] = min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        // using Recursion
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return findAns(grid, dp, 0, 0);
    }
};