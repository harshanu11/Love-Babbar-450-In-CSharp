using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _15_bit_manipulation
{
    public class _07_copy_set_bit_in_range
    {

		/*
    link: https://www.geeksforgeeks.org/copy-set-bits-in-a-range/
*/
		[Fact] public void Test() { }
		// ----------------------------------------------------------------------------------------------------------------------- //

		// here in bit range check if is there any 1 in y then update x if x has 0 at that pos.
		// TC: O(r-l) or O(const.) hence O(1) as r and l will be in range of 32.
		private int newNum(int x, int y, int l, int r)
		{
			for (int i = l; i <= r; i++)
			{
				int temp = 1 << i - 1;
				if ((temp & y) != 0)
				{
					if ((temp & x) != 0)
					{
						continue;
					}
					else
					{
						x |= temp;
					}
				}
			}
			return x;
		}

		// -

	}
}
