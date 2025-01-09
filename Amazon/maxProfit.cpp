class Solution {
public:
    int solveMemo(vector<int>& prices, int i, bool buy, int limit,
                  vector<vector<vector<int>>>& dp) {
        if (i >= prices.size()) {
            return 0;
        }
        if (limit == 0) {
            return 0;
        }
        if (dp[i][buy][limit] != -1) {
            return dp[i][buy][limit];
        }
        int profit;
        if (buy) {
            int profit_Buy =
                -prices[i] + solveMemo(prices, i + 1, 0, limit, dp);
            int profit_Buy_ignore = 0 + solveMemo(prices, i + 1, 1, limit, dp);
            profit = max(profit_Buy, profit_Buy_ignore);
        } else {
            int profit_sell =
                prices[i] + solveMemo(prices, i + 1, 1, limit - 1, dp);
            int profit_sell_ignore = 0 + solveMemo(prices, i + 1, 0, limit, dp);
            profit = max(profit_sell, profit_sell_ignore);
        }
        dp[i][buy][limit] = profit;
        return dp[i][buy][limit];
    }

    int maxProfit(int k, vector<int>& prices) {
        int i = 0;
        bool buy = 1;
        int limit = k;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(buy + 1, vector<int>(limit + 1, -1)));
        return solveMemo(prices, i, buy, limit, dp);
    }
};