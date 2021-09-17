using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _02_matrix
{
    public class _03_median_in_row_wise_sorted_matrix
    {
        /*
			link: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
			sol: https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
			here logic was
			1. based on the total ele in matrix find mid pos (called it desired pos, will help for count)
			2. find max, min
			3. now everytime find mid based on min and max, parallely find count of ele. less than mid and if
			   total count is greater than desired place means our mid is much higher than original one as it is not near
			   to the desired and hence reduce the max, and if count of ele. is less than desired means our mid is way too
			   small and make it greater hence increase the min.
		*/

        [Fact]
        public void Test()
        {
            int r = 3, c = 3;
            int[,] m = {{1,3,5},
              {2,6,9},
              {3,6,9} };

            Console.WriteLine("Median is " +
                               binaryMedian(m, r, c));
        }

        static int binaryMedian(int[,] m,  int r, int c)
        {
            int max = int.MinValue;
            int min = int.MaxValue;

            for (int i = 0; i < r; i++)
            {
                // Finding the minimum
                // element
                if (m[i, 0] < min)
                    min = m[i, 0];

                // Finding the maximum
                // element
                if (m[i, c - 1] > max)
                    max = m[i, c - 1];
            }

            int desired = (r * c + 1) / 2;
            while (min < max)
            {
                int mid = min + (max - min) / 2;
                int place = 0;
                int get = 0;

                // Find count of elements
                // smaller than mid
                for (int i = 0; i < r; ++i)
                {
                    get = Array.BinarySearch(
                          GetRow(m, i), mid);

                    // If element is not found
                    // in the array the binarySearch()
                    // method returns (-(insertion_
                    // point) - 1). So once we know
                    // the insertion point we can
                    // find elements Smaller than
                    // the searched element by the
                    // following calculation
                    if (get < 0)
                        get = Math.Abs(get) - 1;

                    // If element is found in the
                    // array it returns the index(any
                    // index in case of duplicate). So
                    // we go to last index of element
                    // which will give  the number of
                    // elements smaller than the number
                    // including the searched element.
                    else
                    {
                        while (get < GetRow(m, i).GetLength(0) &&
                              m[i, get] == mid)
                            get += 1;
                    }

                    place = place + get;
                }

                if (place < desired)
                    min = mid + 1;
                else
                    max = mid;
            }
            return min;
        }

        public static int[] GetRow(int[,] matrix,
                                   int row)
        {
            var rowLength = matrix.GetLength(1);
            var rowVector = new int[rowLength];

            for (var i = 0; i < rowLength; i++)
                rowVector[i] = matrix[row, i];

            return rowVector;
        }



        // ----------------------------------------------------------------------------------------------------------------------- //
        // function to find median in the matrix
        private int binaryMedian(List<List<int>> matrix, int r, int c)
		{
			int mn = int.MaxValue;
			int mx = int.MinValue;
			for (int i = 0; i < r; i++)
			{
				// Finding the minimum element
				mn = Math.Min(mn, matrix[i][0]);

				// Finding the maximum element
				mx = Math.Max(mn, matrix[i][c - 1]);
			}

			int desired = (r * c + 1) / 2;
			while (mn < mx)
			{
				int mid = mn + (mx - mn) / 2;
				int place = 0;

				// Find count of elements smaller than mid
				for (int i = 0; i < r; ++i)
				{
					//place += upper_bound(matrix[i].GetEnumerator(), matrix[i].GetEnumerator() + c, mid) - matrix[i].GetEnumerator();
					// cout << i << ": " << curr << endl;
				}

				if (place < desired)
				{
					mn = mid + 1;
				}
				else
				{
					mx = mid;
				}
				// cout << mx << " " << mn << endl;
			}
			return mn;
		}

	}
}
