using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _01_array
{
    public class _05_negative_ele_to_one_side_of_array
    {
		/*
			link: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

			variation: 2-pointer
		*/

		[Fact]
		public void reverse_arrayTest() { }
		// ----------------------------------------------------------------------------------------------------------------------- //
		internal void arrange(int[] a, int n)
		{
			int negi = 0;
			int pos = n - 1;

			while (negi <= pos)
			{
				if (a[negi] < 0 && a[pos] < 0)
				{
					negi++;
				}
				else if (a[negi] > 0 && a[pos] < 0)
				{
					//swap(a[negi], a[pos]);
					negi++;
					pos--;
				}
				else if (a[negi] > 0 && a[pos] > 0)
				{
					pos--;
				}
				else
				{
					//low++;
					//high--;
				}
			}
		}

	}
}
