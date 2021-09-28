using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _02_matrix
{
    public class _02_search_an_ele_in_matrix
    {

        /*
            link: https://leetcode.com/problems/search-a-2d-matrix/
        */


        [Fact]
        public void search_matrixTest()
        {
            int[][] arr = new int[3][] { new int[] { 1, 2, 3 }, new int[] { 4, 5, 6 }, new int[] { 7, 8, 9 } };
            var ans = searchMatrix1(arr, 8);
            ans = searchSortedMatrix(arr, 9);
        }


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            simple approach, by smallest ele in row and then smallest ele in that row's col.
            TC: O(max(row, col))
        */
        private bool searchMatrix1(int[][] matrix, int target)
        {
            int row = matrix.Length;
            int col = matrix[0].Length;

            int i = row - 1;
            int j = col - 1;
            while (i > 0 && matrix[i][0] > target) i--;
            while (j > 0 && matrix[i][j] > target) j--;
            return matrix[i][j] == target;
        }


        // ----------------------------------------------------------------------------------------------------------------------- //
        /*
            using binary search
            TC: O(log(mn))
        // sorted array only
        */
        private bool searchSortedMatrix(int[][] matrix, int target)
        {
            // treat the matrix as an array, just taking care of indices
            // [0..n*m]
            // (row, col) -> row*n + col
            // i -> [i/n][i%n]
            if (matrix.Length == 0 || matrix[0].Length == 0) return false;
            int row = matrix.Length;
            int col = matrix[0].Length;
            int start = 0;
            int end = row * col;
            while (start < end)
            {
                int mid = start + (end - start) / 2;
                int midElement = matrix[mid / col][mid % col];
                /*
                    here mid/col show how many complete row do we have
                    while mid % n is just that column doesn't overflow.
                */
                if (target < midElement) end = mid - 1;
                else if (target > midElement) start = mid + 1;
                else return true;
            }
            return false;
        }

    }
}
