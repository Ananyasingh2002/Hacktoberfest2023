class Solution {
public:
	int solveOpti(vector<int> &prices, int n)                       // OPTIMIZED APPROACH
	{
		vector<vector<int>> after(2, vector<int> (3, 0));
		vector<vector<int>> curr(2, vector<int> (3, 0));

		for (int ind=n-1;ind>=0;ind--)
		{
			for (int buy=0;buy<=1;buy++)
			{
				int profit = 0;
				for (int cap=0;cap<=2;cap++)
				{
					if (buy)
						profit = max(-prices[ind] + after[0][cap], after[1][cap]);
					else
						profit = max(prices[ind] + after[1][cap-1], after[0][cap]);

					curr[buy][cap] = profit;
				}
			}
			after = curr;
		}
		return after[1][2];
	}

	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		return solveOpti(prices, n);
	}
};
