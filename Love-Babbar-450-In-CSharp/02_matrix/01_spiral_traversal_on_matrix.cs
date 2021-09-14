using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace Love_Babbar_450_In_CSharp._02_matrix
{
    /*
    link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#

    sol: https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/


    video(for anti-clockwise): https://www.youtube.com/watch?v=SVFXEqn3Ceo
*/




    // ----------------------------------------------------------------------------------------------------------------------- //
    /*
        simple solution just changing direction

        TC: O(m * n)
        SC: O(m * n)
    */
    public class _01_spiral_traversal_on_matrix
    {
        [Fact]
        public void reverse_arrayTest()
        {
            int[][] arr = new int[3][] { new int[]{ 1, 2, 3 }, new int[] { 4, 5, 6 }, new int[] { 7, 8, 9 } };
            SpiralOrder(arr);
        }
        public IList<int> SpiralOrder(int[][] matrix)
        {
            var result = new List<int>();
            if (matrix.Length == 0 || matrix[0].Length == 0)
            {
                return result;
            }
            if (matrix.Length == 1 || matrix[0].Length == 1)
            {
                for (int i = 0; i < matrix.Length; i++)
                {
                    for (int j = 0; j < matrix[0].Length; j++)
                    {
                        result.Add(matrix[i][j]);
                    }
                }

                return result;
            }

            // 4 possible directions of traversal
            // To spiral first traverse right ->, then down ↓, then left <-, and finally up ^.
            int[][] direction = new int[][]
            {
            new int[] {0,1}, // right direction 
            new int[] {1,0}, // down direction
            new int[] {0,-1},// left direction
            new int[] {-1,0} // up direction
            };

            int maxCol = matrix[0].Length;
            int maxRow = matrix.Length;
            int minRow = 0;
            int minCol = 0;

            int currentCol = 0;
            int currentRow = 0;
            int currentDirection = 0;
            int totalElements = maxRow * maxCol;
            while (totalElements-- != 0)
            {

                result.Add(matrix[currentRow][currentCol]);

                currentRow = currentRow + direction[currentDirection][0];
                currentCol = currentCol + direction[currentDirection][1];
                // Direction right means we are traversing the top part of matrix and if hits the boundary then increase minRow++ as the top row is already covered
                if (currentCol == maxCol - 1 && direction[currentDirection][1] == 1 && direction[currentDirection][0] == 0)
                {
                    minRow++;
                    currentDirection = (currentDirection + 1) % 4;
                }

                // Direction bottom means we are traversing the right most part of matrix and if hits the boundary then decrease maxCol-- as last column is alredy covered
                if (currentRow == maxRow - 1 && direction[currentDirection][0] == 1 && direction[currentDirection][1] == 0)
                {
                    maxCol--;
                    currentDirection = (currentDirection + 1) % 4;
                }

                // Direction left means we are traversing the bottom part of matrix and if hits the boundary then decrease maxRow-- as bottom row is alredy covered            
                if (currentCol == minCol && direction[currentDirection][1] == -1 && direction[currentDirection][0] == 0)
                {
                    maxRow--;
                    currentDirection = (currentDirection + 1) % 4;
                }

                // Direction up means we are traversing the left part of matrix and if hits the boundary then firts column in already covered and hence increase minCol++
                if (currentRow == minRow && direction[currentDirection][0] == -1 && direction[currentDirection][1] == 0)
                {
                    minCol++;
                    currentDirection = (currentDirection + 1) % 4;
                }
            }

            return result;
        }

    }
}
