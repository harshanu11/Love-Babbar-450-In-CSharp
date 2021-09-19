using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _15_bit_manipulation
{
    public class _06_find_pos_of_set_bit
    {

        [Fact] public void Test() { }
		/*
    link: https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1#
*/

		// ----------------------------------------------------------------------------------------------------------------------- //

		// TC: O(log N)
		private int findPosition(int n)
		{
			int count = 0;
			int setBit = 0;
			while (n != 0)
			{
				count++;
				if ((n & 1) != 0)
				{
					setBit++;
				}
				n >>= 1;
			}
			if (setBit > 1 || setBit == 0)
			{
				return -1;
			}
			return count;
		}

		// ----

	}
}
