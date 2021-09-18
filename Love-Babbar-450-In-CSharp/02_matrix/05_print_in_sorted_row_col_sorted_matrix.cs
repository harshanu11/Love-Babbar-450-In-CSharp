using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _02_matrix
{
    public class _05_print_in_sorted_row_col_sorted_matrix
    {
        [Fact]
        public void reverse_arrayTest() { }

        /*
            link: https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1
        */
        // ----------------------------------------------------------------------------------------------------------------------- //
        private List<List<int>> sortedMatrix(int n, List<List<int>> mat)
        {
            // code here
            List<int> temp = new List<int>();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    temp.Add(mat[i][j]);
                }
            }
            temp.Sort();

            int k = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mat[i][j] = temp[k++];
                }
            }
            return new List<List<int>>(mat);
        }

    }
}
