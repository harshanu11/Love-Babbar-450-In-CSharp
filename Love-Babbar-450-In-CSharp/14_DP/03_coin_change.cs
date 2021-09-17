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
