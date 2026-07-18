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
        // using tabulation
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // row1
        for(int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        // row2 to m
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int paths = 0;
                if(j!=0) paths = dp[i][j-1];
                if(i!=0) paths += dp[i-1][j];
                dp[i][j] = paths;
            }
        }

        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[m-1][n-1];
    }
};