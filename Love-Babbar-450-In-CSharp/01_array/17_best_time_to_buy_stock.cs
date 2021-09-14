/*
    link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    also refer to 26_sell_...twice.cpp
*/


// ----------------------------------------------------------------------------------------------------------------------- //
using System;
using System.Collections.Generic;

private int maxProfit(List<int> prices)
{
	int n = prices.Count;
	int local = 0;
	int global = 0;
	for (int i = 1; i < n; i++)
	{
		/*
		    if the loss is going negative then make it 0 either continue with the profit as higher as possible.
		*/
		local = Math.Max(0, local += prices[i] - prices[i - 1]);
		global = Math.Max(local, global);
	}
	return global;
}

