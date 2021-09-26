using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace _02_matrix
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
        public void Spiral_MatrixTest()
        {
            int[][] arr = new int[3][] { new int[] { 1, 2, 3 }, new int[] { 4, 5, 6 }, new int[] { 7, 8, 9 } };
            List<List<int>> lst = new List<List<int>>() { new List<int>() { 1, 2, 3 }, new List<int>() { 4, 5, 6 }, new List<int>() { 7, 8, 9 } };

            var ans = spiralOrder(arr, 3, 3);
            ans = SpiralOrder1(arr);
            ans = spiralOrder3(arr, 3, 3);
            ans = SpiralOrder2(lst, 3, 3);
        }
        public List<int> spiralOrder(int[][] matrix, int row, int col)
        {
            List<int> ans = new List<int>();
            if (matrix == null || row == 0) return ans;
            int up = 0, down = row - 1;
            int left = 0, right = col - 1;
            while (ans.Count < row * col)
            {
                for (int lr = left; lr <= right && ans.Count < row * col; lr++)
                    ans.Add(matrix[up][lr]);
                for (int ud = up + 1; ud <= down - 1 && ans.Count < row * col; ud++)
                    ans.Add(matrix[ud][right]);
                for (int lr = right; lr >= left && ans.Count < row * col; lr--)
                    ans.Add(matrix[down][lr]);
                for (int ud = down - 1; ud >= up + 1 && ans.Count < row * col; ud--)
                    ans.Add(matrix[ud][left]);
                left++; right--; up++; down--;
            }
            return ans;
        }
        public List<int> SpiralOrder1(int[][] matrix)
        {
            var result = new List<int>();
            if (matrix.Length == 0 || matrix[0].Length == 0)
            {
                return result;
            }
            if (matrix.Length == 1 || matrix[0].Length == 1)
            {
                for (int row = 0; row < matrix.Length; row++)
                {
                    for (int col = 0; col < matrix[0].Length; col++)
                    {
                        result.Add(matrix[row][col]);
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
        public List<int> SpiralOrder2(List<List<int>> matrix, int r, int c)
        {
            var result = new List<int>();
            if (r == 0 || c == 0) return result;
            if (r == 1 || c == 1)
            {
                for (int row = 0; row < r; row++)
                {
                    for (int col = 0; col < c; col++)
                    {
                        result.Add(matrix[row][col]);
                    }
                }
                return result;
            }

            int[][] direction = new int[][]
            {
                new int[] {0,1}, // right direction 
                new int[] {1,0}, // down direction
                new int[] {0,-1},// left direction
                new int[] {-1,0} // up direction
            };
            int totalElements = r * c;

            int minRow = 0;
            int minCol = 0;
            int curCol = 0;
            int curRow = 0;
            int curDir = 0;

            while (totalElements-- != 0)
            {

                result.Add(matrix[curRow][curCol]);

                curRow = curRow + direction[curDir][0];
                curCol = curCol + direction[curDir][1];
                if (curCol == c - 1 && direction[curDir][1] == 1 && direction[curDir][0] == 0)
                {
                    minRow++;
                    //1%4= 1,2 % 4=2,3 % 4=3,4 % 4=0,5 % 4=1,6 % 4=2,7 % 4=3,8 % 4=00
                    curDir = (curDir + 1) % 4;
                }
                if (curRow == r - 1 && direction[curDir][0] == 1 && direction[curDir][1] == 0)
                {
                    c--;
                    curDir = (curDir + 1) % 4;
                }
                if (curCol == minCol && direction[curDir][1] == -1 && direction[curDir][0] == 0)
                {
                    r--;
                    curDir = (curDir + 1) % 4;
                }
                if (curRow == minRow && direction[curDir][0] == -1 && direction[curDir][1] == 0)
                {
                    minCol++;
                    curDir = (curDir + 1) % 4;
                }
            }

            return result;
        }
        public List<int> spiralOrder3(int[][] matrix, int r, int c)
        {

            List<int> res = new List<int>();

            if (r == 0)
            {
                return res;
            }

            int rowBegin = 0;
            int rowEnd = r - 1;
            int colBegin = 0;
            int colEnd = c - 1;

            while (rowBegin <= rowEnd && colBegin <= colEnd)
            {
                // Traverse Right
                for (int j = colBegin; j <= colEnd; j++)
                {
                    res.Add(matrix[rowBegin][j]);
                }
                rowBegin++;

                // Traverse Down
                for (int j = rowBegin; j <= rowEnd; j++)
                {
                    res.Add(matrix[j][colEnd]);
                }
                colEnd--;

                if (rowBegin <= rowEnd)
                {
                    // Traverse Left
                    for (int j = colEnd; j >= colBegin; j--)
                    {
                        res.Add(matrix[rowEnd][j]);
                    }
                }
                rowEnd--;

                if (colBegin <= colEnd)
                {
                    // Traver Up
                    for (int j = rowEnd; j >= rowBegin; j--)
                    {
                        res.Add(matrix[j][colBegin]);
                    }
                }
                colBegin++;
            }

            return res;
        }
       

    }
}
