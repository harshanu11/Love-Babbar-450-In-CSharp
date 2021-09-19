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
        N=4
Mat=[[10,20,30,40],
[15,25,35,45] 
[27,29,37,48] 
[32,33,39,50]]
Output:
10 15 20 25 
27 29 30 32
33 35 37 39
40 45 48 50
Explanation:
Sorting the matrix gives this result.
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
/*
    link: https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1
*/


//// ----------------------------------------------------------------------------------------------------------------------- //
//vector<vector<int>> sortedMatrix(int n, vector<vector<int>> mat)
//{
//    // code here
//    vector<int> temp;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            temp.push_back(mat[i][j]);
//        }
//    }
//    sort(temp.begin(), temp.end());

//    int k = 0;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            mat[i][j] = temp[k++];
//        }
//    }
//    return mat;
//}