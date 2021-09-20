using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _14_DP
{
    public class _03_coin_change
    {
		[Fact]
		public void reverse_arrayTest()
		{

		}
		internal class Solution
		{
			public virtual long count(int[] S, int m, int n)
			{
				long[] table = new long[n + 1];
				for (int i = 0; i < n + 1; i++)
				{
					table[i] = 0;
				}
				table[0] = 1;
				for (int i = 0; i < m; i++)
				{
					for (int j = S[i]; j <= n; j++)
					{
						table[j] += table[j - S[i]];
					}
				}

				return table[n];

			}
		}

	}
}
/*
    link: https://practice.geeksforgeeks.org/problems/coin-change2448/1

    variation of unbounded_knapsack for more refer to DP_tut/unbounded_knapsack/3_coin....
*/

//// ----------------------------------------------------------------------------------------------------------------------- //

//long long int count(int coins[], int n, int sum)
//{
//	vector < vector < long long int>> memo(n + 1, vector < long long int > (sum + 1));
//	for (int j = 0; j < sum + 1; j++) memo[0][j] = 0;
//	for (int i = 1; i < n + 1; i++) memo[i][0] = 1;

//	for (int i = 1; i < n + 1; i++)
//	{
//		for (int j = 1; j < sum + 1; j++)
//		{
//			if (coins[i - 1] <= j)
//			{
//				memo[i][j] = memo[i][j - coins[i - 1]] + memo[i - 1][j];
//			}
//			else memo[i][j] = memo[i - 1][j];
//		}
//	}
//	return memo[n][sum];
//}

//// ----------------------------------------------------------------------------------------------------------------------- //