using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _17_best_time_to_buy_stock
    {
		/*
		    link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
		
		    also refer to 26_sell_...twice.cpp

		You are given an array prices where prices[i] is the price of a given stock on the ith day.

		You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
		
		Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
		
		 
		
		Example 1:
		
		Input: prices = [7,1,5,3,6,4]
		Output: 5
		Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
		Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
		*/


		// ----------------------------------------------------------------------------------------------------------------------- //
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

		[Fact] public void Test() { }
    }
}
/*
    link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    also refer to 26_sell_...twice.cpp
*/


//// ----------------------------------------------------------------------------------------------------------------------- //
//int maxProfit(vector<int>& prices)
//{
//	int n = prices.size();
//	int local = 0, global = 0;
//	for (int i = 1; i < n; i++)
//	{
//		/*
//            if the loss is going negative then make it 0 either continue with the profit as higher as possible.
//        */
//		local = max(0, local += prices[i] - prices[i - 1]);
//		global = max(local, global);
//	}
//	return global;
//}
