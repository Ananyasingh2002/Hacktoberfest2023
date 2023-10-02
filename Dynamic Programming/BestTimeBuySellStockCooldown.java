//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution {
    public int maxProfit(int[] prices) {
        
        if(prices == null || prices.length<=1) return 0;

        int n = prices.length;
        int [] profit = new int[n];

        profit[0] = 0;
        profit[1] = Math.max(0, prices[1] - prices[0]);

        for(int i=2;i<n;i++){
            profit[i] = profit[i-1];

            for(int j=0;j<i;j++){
                int prev_profit = j>=2 ? profit[j-2] : 0;
                profit[i] = Math.max(profit[i], prev_profit + prices[i] - prices[j]);
            }
        }

        return profit[n-1];
    }
}
