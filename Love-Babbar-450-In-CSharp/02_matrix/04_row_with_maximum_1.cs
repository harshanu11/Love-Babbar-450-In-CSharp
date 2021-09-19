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
            int[,] arr = new int[,]{{0, 1, 1, 1},
                                    {0, 0, 1, 1},
                                    {1, 1, 1, 1},
                                    {0, 0, 0, 0}}
                                    ;

            var ans = rowWithMax1s(arr,4,4);
        }


        /*
            link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

            logic: if we get 1 shift to left and if not then shift to bottom
        */


        // ----------------------------------------------------------------------------------------------------------------------- //
        // TC: O(m+n)
        int rowWithMax1s(int[,] arr, int n, int m)
        {
            int r = 0;              // keeps track of row; starts at first row             
            int c = m - 1;            // keeps track of column; starts at last column
            int max_row_index = -1;   // keeps track of result row index

            // starting from top right corner
            // go left if you encounter 1
            // do down if you encounter 0
            while (r < n && c >= 0)
            {
                if (arr[r,c] == 1)
                {
                    max_row_index = r;
                    c--;
                }
                else
                    r++;
            }
            return max_row_index;
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
/*
    link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

    logic: if we get 1 shift to left and if not then shift to bottom
*/


//// ----------------------------------------------------------------------------------------------------------------------- //
//// TC: O(m+n)
//int rowWithMax1s(vector<vector<int>> arr, int n, int m)
//{
//    // code here
//    int row = 0, col = m - 1, ans = -1;

//    while (col >= 0 && row < n)
//    {
//        if (arr[row][col] == 1)
//        {
//            one = max(one, col);
//            ans = max(ans, row);
//            col--;
//        }
//        else row++;
//    }
//    return ans;
//}




//// ----------------------------------------------------------------------------------------------------------------------- //
//// similar solution
//int rowWithMax1s(vector<vector<int>> arr, int n, int m)
//{
//    int r = 0;              // keeps track of row; starts at first row             
//    int c = m - 1;            // keeps track of column; starts at last column
//    int max_row_index = -1;   // keeps track of result row index

//    // starting from top right corner
//    // go left if you encounter 1
//    // do down if you encounter 0
//    while (r < n && c >= 0)
//    {
//        if (arr[r][c] == 1)
//        {
//            max_row_index = r;
//            c--;
//        }
//        else
//            r++;
//    }
//    return max_row_index;
//}