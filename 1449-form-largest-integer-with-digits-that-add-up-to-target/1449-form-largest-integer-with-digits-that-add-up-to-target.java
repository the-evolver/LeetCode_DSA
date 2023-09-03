class Solution {
    public String largestNumber(int[] cost, int target) {
        int[] dp = new int[target + 1];
        for (int t = 1; t <= target; ++t) {
            dp[t] = -10000;
            for (int i = 0; i < 9; ++i) {
                if (t >= cost[i])
                    dp[t] = Math.max(dp[t], 1 + dp[t - cost[i]]);
            }
        }
        if (dp[target] < 0) return "0";
        StringBuilder res = new StringBuilder();
        for (int i = 8; i >= 0; --i) {
            while (target >= cost[i] && dp[target] == dp[target - cost[i]] + 1) {
                res.append(1 + i);
                target -= cost[i];
            }
        }
        return res.toString();
    }

}