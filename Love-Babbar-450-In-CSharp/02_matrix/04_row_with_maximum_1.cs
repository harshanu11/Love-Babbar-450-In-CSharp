using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _02_matrix
{
    public class _04_row_with_maximum_1
    {
        [Fact]
        public void reverse_arrayTest()
        {


        }


/*
    link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

    logic: if we get 1 shift to left and if not then shift to bottom
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// TC: O(m+n)
private int rowWithMax1s1(List<List<int>> arr, int n, int m)
	{
		// code here
		int row = 0;
		int col = m - 1;
		int ans = -1;

		while (col >= 0 && row < n)
		{
			if (arr[row][col] == 1)
			{
				//one = Math.Max(one, col);
				ans = Math.Max(ans, row);
				col--;
			}
			else
			{
				row++;
			}
		}
		return ans;
	}




	// ----------------------------------------------------------------------------------------------------------------------- //
	// similar solution
	private int rowWithMax1s2(List<List<int>> arr, int n, int m)
	{
		int r = 0; // keeps track of row; starts at first row
		int c = m - 1; // keeps track of column; starts at last column
		int max_row_index = -1; // keeps track of result row index

		// starting from top right corner
		// go left if you encounter 1
		// do down if you encounter 0
		while (r < n && c >= 0)
		{
			if (arr[r][c] == 1)
			{
				max_row_index = r;
				c--;
			}
			else
			{
				r++;
			}
		}
		return max_row_index;
	}

}
}
