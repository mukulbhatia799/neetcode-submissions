class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // optimal approach - t.c -> O(n) and s.c -> O(1)
        int n = prices.size();
        
        int mini = INT_MAX;
        int ans = 0;
        for(int price : prices) {
            int profit = price - mini;
            ans = max(ans, profit);
            mini = min(mini, price);
        }

        return ans;
        
    }
};