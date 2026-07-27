class Solution {
public:
    int trap(vector<int>& height) {
        // t.c -> O(n) + O(n) + o(n) -> O(3n) ~ O(n)
        int n = height.size();
        vector<int> right(n, -1);

        // fill rightMax[] - right to left
        int maxx = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            maxx = max(maxx, height[i]);
            right[i] = maxx;
        }

        // now, min(leftMax, rightMax) - height[i]
        int ans = 0, leftMax = height[0];
        for(int i = 1; i < n-1; i++) {
            int rightMax = right[i];
            int water_stored = min(leftMax, rightMax) - height[i];
            if(water_stored > 0) ans += water_stored;
            leftMax = max(leftMax, height[i]);
        }

        return ans;
    }
};