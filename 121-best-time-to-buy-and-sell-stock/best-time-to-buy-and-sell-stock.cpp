class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // better approach - t.c -> O(n) and s.c -> O(n)
        int n = prices.size();
        
        vector<int> rightMax(n, 0);
        rightMax[n-1] = prices[n-1];
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(prices[i], rightMax[i+1]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int sellProfit = rightMax[i] - prices[i];
            ans = max(ans, sellProfit);
        }
        
        return ans;
    }
};