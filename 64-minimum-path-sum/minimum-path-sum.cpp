class Solution {
public:
    // int findAns(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col) {
    //     if(row == grid.size()-1 && col == grid[0].size()-1) return grid[row][col];
    //     if(row >= grid.size() || col >= grid[0].size()) return 1e5;

    //     if(dp[row][col] != -1) return dp[row][col];
    //     int down = grid[row][col] + findAns(grid, dp, row+1, col);
    //     int right = grid[row][col] + findAns(grid, dp, row, col+1);

    //     return dp[row][col] = min(down, right);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        // using Tabulation
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++) dp[0][i] = grid[0][i] + dp[0][i-1];
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int left = 1e5, top = 1e5;
                if(j-1 >= 0) left = grid[i][j] + dp[i][j-1];
                top = grid[i][j] + dp[i-1][j];
                dp[i][j] = min(left, top);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return dp[n-1][m-1];

    }
};