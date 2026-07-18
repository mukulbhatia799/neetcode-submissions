class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // using Tabulation
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m, 0);
        dp[0] = grid[0][0];
        for(int i = 1; i < m; i++) dp[i] = grid[0][i] + dp[i-1];
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int left = 1e5, top = 1e5;
                if(j-1 >= 0) left = grid[i][j] + dp[j-1];
                top = grid[i][j] + dp[j];
                dp[j] = min(left, top);
            }
        }

        return dp[m-1];

    }
};