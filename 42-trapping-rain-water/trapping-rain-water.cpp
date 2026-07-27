class Solution {
public:
    int trap(vector<int>& height) {
        // t.c -> O(n) + O(n) + o(n) -> O(3n) ~ O(n)
        int n = height.size();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        int maxx = height[0];
        // fill leftMax[] - left to right
        for(int i = 1; i < n; i++) {
            maxx = max(maxx, height[i]);
            left[i] = maxx;
        }

        // fill rightMax[] - right to left
        maxx = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            maxx = max(maxx, height[i]);
            right[i] = maxx;
        }

        // now, min(leftMax, rightMax) - height[i]
        int ans = 0;
        for(int i = 1; i < n-1; i++) {
            int leftMax = left[i];
            int rightMax = right[i];
            int waterStored = min(leftMax, rightMax) - height[i];
            if(waterStored > 0) ans += waterStored;
        }

        return ans;
    }
};