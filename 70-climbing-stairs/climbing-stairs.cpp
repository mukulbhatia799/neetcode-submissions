class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        // using space optimization - O(n) t.c, O(1) s.c
        int f = 1;
        int s = 1;
        int t = 0;
        for(int i = 2; i <= n; i++) {
            t = f+s;
            f = s;
            s = t;
        }

        return t;
    }
};